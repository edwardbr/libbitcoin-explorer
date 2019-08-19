hunter_config(Boost VERSION 1.70.0-p0)

hunter_config(secp256k1
    URL https://github.com/edwardbr/secp256k1/archive/master.tar.gz
    SHA1 7229336a56a3d0171cc6c6055bf4f0635435e0cb)


hunter_config(libbitcoin-system
    URL https://github.com/edwardbr/libbitcoin-system/archive/master.tar.gz
    SHA1 e23ed1d464841aaf3a520f76db662b9f136c7261
    CMAKE_ARGS
        with-icu=NO
        )

hunter_config(libbitcoin-network
    URL https://github.com/edwardbr/libbitcoin-network/archive/master.tar.gz
    SHA1 6fb03a39132d94bed5f15ce73f87f610bab0b1a6
    CMAKE_ARGS
        with-icu=NO
        )        

hunter_config(libbitcoin-protocol
    URL https://github.com/edwardbr/libbitcoin-protocol/archive/master.tar.gz
    SHA1 72438ec06c214a4a58fd31dda5e95bfeca03a89f
    CMAKE_ARGS
        with-icu=NO
        )

hunter_config(libbitcoin-client
    URL https://github.com/edwardbr/libbitcoin-client/archive/master.tar.gz
    SHA1 ed89f89c1faf631af10ce2fdb2571434a18ace1e
    CMAKE_ARGS
        with-icu=NO
        )

hunter_config(ICU VERSION 63.1-p5)