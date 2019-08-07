hunter_config(Boost VERSION 1.70.0-p0)

hunter_config(secp256k1
    URL https://github.com/edwardbr/secp256k1/archive/master.tar.gz
    SHA1 7229336a56a3d0171cc6c6055bf4f0635435e0cb)


hunter_config(libbitcoin-system
    URL https://github.com/edwardbr/libbitcoin-system/archive/master.tar.gz
    SHA1 d1de11c54e1b387ee74809cfa00e4b35331a002b
    CMAKE_ARGS
        with-icu=YES
        )

hunter_config(libbitcoin-network
    URL https://github.com/edwardbr/libbitcoin-network/archive/master.tar.gz
    SHA1 5c04204a22b59e893c6d6dede25966cb4d04b0a8
    CMAKE_ARGS
        with-icu=YES
        )        

hunter_config(libbitcoin-protocol
    URL https://github.com/edwardbr/libbitcoin-protocol/archive/master.tar.gz
    SHA1 72438ec06c214a4a58fd31dda5e95bfeca03a89f
    CMAKE_ARGS
        with-icu=YES
        )

hunter_config(libbitcoin-client
    URL https://github.com/edwardbr/libbitcoin-client/archive/master.tar.gz
    SHA1 b5ea77d22a57c32a69d24611b8cddbe1d3198904
    CMAKE_ARGS
        with-icu=YES
        )

hunter_config(ICU VERSION 63.1-p5)