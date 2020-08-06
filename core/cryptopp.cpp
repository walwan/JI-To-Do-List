#include "cryptopp.h"

//Crypto++ Headers
#include "filters.h"
using CryptoPP::HashFilter;
using CryptoPP::Redirector;
using CryptoPP::StringSink;
using CryptoPP::StringSource;
using CryptoPP::AuthenticatedEncryptionFilter;
using CryptoPP::AuthenticatedDecryptionFilter;

#include "hex.h"
using CryptoPP::HexEncoder;
using CryptoPP::HexDecoder;

#include "sha.h"
using CryptoPP::SHA1;

#include "gcm.h"
using CryptoPP::GCM;

#include "osrng.h"
using CryptoPP::AutoSeededRandomPool;

#include "secblock.h"
using CryptoPP::SecByteBlock;

using CryptoPP::byte;
using CryptoPP::word64;

#include <iostream>
using std::endl;
using std::cerr;

string pwdHashKey;
string iv;

const int TAG_SIZE = 12;

string encode_hex(const string &text){
    string hex;

    StringSource encodeS(text, true, new HexEncoder(new StringSink(hex)));

    return hex;
}

string encode_hex(const char *text, size_t len){
    string hex;

    StringSource((byte *) text, len, true, new HexEncoder(new StringSink(hex)));

    return hex;
}

string decode_hex(const string &hex){
    string decoded;

    HexDecoder decoder;
    decoder.Put( (byte*)hex.data(), hex.size() );
    decoder.MessageEnd();

    word64 size = decoder.MaxRetrievable();
    if(size && size <= SIZE_MAX)
    {
        decoded.resize(size);
        decoder.Get((byte*)&decoded[0], decoded.size());
    }

    return decoded;
}

string randomPool(const size_t len){
    byte tmp[len];

    AutoSeededRandomPool prng;
    prng.GenerateBlock(tmp, len);

    return encode_hex((char *) tmp, len);
}

string sha1(const string &text, const int len){
    SHA1 hash;
    string digest;

    HexEncoder encoder(new StringSink(digest));
    StringSource(text, true, new HashFilter(hash, new Redirector(encoder)));

    digest.resize(len);
    return digest;
}

string encrypt(const string data, const string key, const string ivHex){
    string iv = decode_hex(ivHex);

    string cipher;

    try
    {
        GCM<AES>::Encryption e;
        e.SetKeyWithIV((unsigned char *) key.c_str(), key.size(), (unsigned char *) iv.c_str(), iv.size());

        StringSource ss1( data, true,
            new AuthenticatedEncryptionFilter( e,
                new StringSink( cipher ), false, TAG_SIZE
            ) // AuthenticatedEncryptionFilter
        ); // StringSource
    }
    catch( CryptoPP::Exception& e )
    {
        cerr << e.what() << endl;
        exit(1);
    }


    return encode_hex(cipher);
}

string decrypt(const string cipherhex, const string key, const string ivHex){
    string iv =  decode_hex(ivHex);
    string cipher = decode_hex(cipherhex);

    string data;

    try
    {
        GCM< AES >::Decryption d;
        d.SetKeyWithIV((unsigned char *) key.c_str(), key.size(), (unsigned char *) iv.c_str(), iv.size());

        AuthenticatedDecryptionFilter df( d,
            new StringSink( data ),
            AuthenticatedDecryptionFilter::DEFAULT_FLAGS, TAG_SIZE
        ); // AuthenticatedDecryptionFilter

        // The StringSource dtor will be called immediately
        //  after construction below. This will cause the
        //  destruction of objects it owns. To stop the
        //  behavior so we can get the decoding result from
        //  the DecryptionFilter, we must use a redirector
        //  or manually Put(...) into the filter without
        //  using a StringSource.
        StringSource ss2( cipher, true,
            new Redirector( df /*, PASS_EVERYTHING */ )
        ); // StringSource

        // If the object does not throw, here's the only
        //  opportunity to check the data's integrity
        if( true == df.GetLastResult() ) {
            //cout << "recovered text: " << rpdata << endl;
        }
    }
    catch( CryptoPP::Exception& e )
    {
        cerr << e.what() << endl;
        exit(1);
    }

    return data;
}
