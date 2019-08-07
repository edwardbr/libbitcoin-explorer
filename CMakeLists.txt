# Copyright (c) 2017 The Bitcoin developers

cmake_minimum_required(VERSION 3.5)


set(CMAKE_VERBOSE_MAKEFILE ON)
list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)


include(HunterGate)

message(STATUS "[project] CMAKE_TOOLCHAIN_FILE: ${CMAKE_TOOLCHAIN_FILE}")

option(HUNTER_STATUS_DEBUG "Hunter debug info" ON)
HunterGate(
    URL "https://github.com/ruslo/hunter/archive/v0.23.165.tar.gz"
    SHA1 "5a73f91df5f6109c0bb1104d0c0ee423f7bece79"
    LOCAL
)

set(HUNTER_KEEP_PACKAGE_SOURCES ON)
option(HUNTER_STATUS_DEBUG "Hunter debug info" ON)

project(libbitcoin-explorer VERSION 0.1)

include(CTest)
include(GNUInstallDirs)

add_definitions( -DSYSCONFDIR="${SYSCONFDIR}" )

# Implement -Dbash-completiondir and output ${bash-completiondir} and declare bash-completiondir.
#------------------------------------------------------------------------------
set( bash-completiondir "no" CACHE BOOL "Install bash completion support, optionally specifying the directory. This option may require elevated permissions." )

# Implement -Dwith-tests and declare with-tests.
#------------------------------------------------------------------------------
set( with-tests "yes" CACHE BOOL "Compile with unit tests." )

# Implement -Dwith-console and declare with-console.
#------------------------------------------------------------------------------
set( with-console "yes" CACHE BOOL "Compile console application." )

# Find secp256k1
#------------------------------------------------------------------------------

hunter_add_package(secp256k1)
find_package(secp256k1 CONFIG REQUIRED)

# Find boost
#------------------------------------------------------------------------------

hunter_add_package(Boost COMPONENTS 
    atomic
    chrono
    date_time
    filesystem
    iostreams
    log
    program_options
    regex
    system
    thread
    test)

find_package(Boost CONFIG REQUIRED 
    atomic
    chrono
    date_time
    filesystem
    iostreams
    log_setup
    log
    program_options
    regex
    system
    thread
    unit_test_framework)

hunter_add_package(libbitcoin-system)
find_package(libbitcoin-system CONFIG REQUIRED)

hunter_add_package(libbitcoin-network)
find_package(libbitcoin-network CONFIG REQUIRED)

hunter_add_package(libbitcoin-protocol)
find_package(libbitcoin-protocol CONFIG REQUIRED)

hunter_add_package(libbitcoin-client)
find_package(libbitcoin-client CONFIG REQUIRED)

hunter_add_package(ICU)
find_package(ICU CONFIG REQUIRED)

hunter_add_package(ZeroMQ)
find_package(ZeroMQ CONFIG REQUIRED)

add_library( ${PROJECT_NAME}
    "src/callback_state.cpp"
    "src/dispatch.cpp"
    "src/display.cpp"
    "src/generated.cpp"
    "src/parser.cpp"
    "src/prop_tree.cpp"
    "src/utility.cpp"
    "src/commands/address-decode.cpp"
    "src/commands/address-embed.cpp"
    "src/commands/address-encode.cpp"
    "src/commands/address-to-key.cpp"
    "src/commands/base16-decode.cpp"
    "src/commands/base16-encode.cpp"
    "src/commands/base58-decode.cpp"
    "src/commands/base58-encode.cpp"
    "src/commands/base58check-decode.cpp"
    "src/commands/base58check-encode.cpp"
    "src/commands/base64-decode.cpp"
    "src/commands/base64-encode.cpp"
    "src/commands/bitcoin160.cpp"
    "src/commands/bitcoin256.cpp"
    "src/commands/btc-to-satoshi.cpp"
    "src/commands/cert-new.cpp"
    "src/commands/cert-public.cpp"
    "src/commands/ec-add-secrets.cpp"
    "src/commands/ec-add.cpp"
    "src/commands/ec-decompress.cpp"
    "src/commands/ec-multiply-secrets.cpp"
    "src/commands/ec-multiply.cpp"
    "src/commands/ec-new.cpp"
    "src/commands/ec-to-address.cpp"
    "src/commands/ec-to-ek.cpp"
    "src/commands/ec-to-public.cpp"
    "src/commands/ec-to-wif.cpp"
    "src/commands/ek-address.cpp"
    "src/commands/ek-new.cpp"
    "src/commands/ek-public-to-address.cpp"
    "src/commands/ek-public-to-ec.cpp"
    "src/commands/ek-public.cpp"
    "src/commands/ek-to-address.cpp"
    "src/commands/ek-to-ec.cpp"
    "src/commands/electrum-new.cpp"
    "src/commands/electrum-to-seed.cpp"
    "src/commands/fetch-balance.cpp"
    "src/commands/fetch-block-hashes.cpp"
    "src/commands/fetch-block-height.cpp"
    "src/commands/fetch-block.cpp"
    "src/commands/fetch-header.cpp"
    "src/commands/fetch-height.cpp"
    "src/commands/fetch-history.cpp"
    "src/commands/fetch-public-key.cpp"
    "src/commands/fetch-stealth.cpp"
    "src/commands/fetch-tx-index.cpp"
    "src/commands/fetch-tx.cpp"
    "src/commands/fetch-utxo.cpp"
    "src/commands/hd-new.cpp"
    "src/commands/hd-private.cpp"
    "src/commands/hd-public.cpp"
    "src/commands/hd-to-address.cpp"
    "src/commands/hd-to-ec.cpp"
    "src/commands/hd-to-public.cpp"
    "src/commands/hd-to-wif.cpp"
    "src/commands/help.cpp"
    "src/commands/input-set.cpp"
    "src/commands/input-sign.cpp"
    "src/commands/input-validate.cpp"
    "src/commands/message-sign.cpp"
    "src/commands/message-validate.cpp"
    "src/commands/mnemonic-decode.cpp"
    "src/commands/mnemonic-encode.cpp"
    "src/commands/mnemonic-new.cpp"
    "src/commands/mnemonic-to-seed.cpp"
    "src/commands/qrcode.cpp"
    "src/commands/ripemd160.cpp"
    "src/commands/satoshi-to-btc.cpp"
    "src/commands/script-decode.cpp"
    "src/commands/script-encode.cpp"
    "src/commands/script-to-address.cpp"
    "src/commands/script-to-key.cpp"
    "src/commands/seed.cpp"
    "src/commands/send-tx-node.cpp"
    "src/commands/send-tx-p2p.cpp"
    "src/commands/send-tx.cpp"
    "src/commands/settings.cpp"
    "src/commands/sha160.cpp"
    "src/commands/sha256.cpp"
    "src/commands/sha512.cpp"
    "src/commands/stealth-decode.cpp"
    "src/commands/stealth-encode.cpp"
    "src/commands/stealth-public.cpp"
    "src/commands/stealth-secret.cpp"
    "src/commands/stealth-shared.cpp"
    "src/commands/subscribe-block.cpp"
    "src/commands/subscribe-tx.cpp"
    "src/commands/token-new.cpp"
    "src/commands/tx-decode.cpp"
    "src/commands/tx-encode.cpp"
    "src/commands/tx-sign.cpp"
    "src/commands/uri-decode.cpp"
    "src/commands/uri-encode.cpp"
    "src/commands/validate-tx.cpp"
    "src/commands/version.cpp"
    "src/commands/watch-key.cpp"
    "src/commands/watch-stealth.cpp"
    "src/commands/watch-tx.cpp"
    "src/commands/wif-to-ec.cpp"
    "src/commands/wif-to-public.cpp"
    "src/commands/wrap-decode.cpp"
    "src/commands/wrap-encode.cpp"
    "src/config/address.cpp"
    "src/config/algorithm.cpp"
    "src/config/btc.cpp"
    "src/config/byte.cpp"
    "src/config/cert_key.cpp"
    "src/config/ec_private.cpp"
    "src/config/electrum.cpp"
    "src/config/encoding.cpp"
    "src/config/endorsement.cpp"
    "src/config/hashtype.cpp"
    "src/config/hd_key.cpp"
    "src/config/language.cpp"
    "src/config/raw.cpp"
    "src/config/signature.cpp"
    "src/config/wrapper.cpp" )



# libsecp256k1 use a different set of flags.
target_compile_options(${PROJECT_NAME} PRIVATE
     "-Wall" 

    # Warn on extra stuff.
    "-Wextra" 

    # Be really annoying.
    "-Wpedantic" 

    # Disallow warning on style order of declarations.
    "-Wno-reorder" 

    # Suppress warning for incomplete field initialization.
    "-Wno-missing-field-initializers" 

    # Conform to style.
    "-Wno-missing-braces" 

    # Ignore comments within comments or commenting of backslash extended lines.
    "-Wno-comment" 

    # Clean up bx generated code.
    "-Wno-unused-parameter"
)


# Conflict in stdlib under clang.
if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
     target_compile_options(${PROJECT_NAME} PRIVATE "-Wno-mismatched-tags") 
endif()

# Limit delays and warnings.
if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
     target_compile_options(${PROJECT_NAME} PRIVATE "-fno-var-tracking-assignments" )
endif()

target_include_directories( ${PROJECT_NAME} PRIVATE include)

target_link_libraries( ${PROJECT_NAME}  
                            Boost::chrono
                            Boost::date_time
                            Boost::filesystem
                            Boost::iostreams
                            Boost::log_setup
                            Boost::log
                            Boost::program_options
                            Boost::regex
                            Boost::system
                            Boost::thread
                            Threads::Threads
                            secp256k1::secp256k1
                            libbitcoin-system::libbitcoin-system   
                            libbitcoin-network::libbitcoin-network 
                            libbitcoin-protocol::libbitcoin-protocol   
                            libbitcoin-client::libbitcoin-client                         
                            ICU::uc)

# Define bx project.
#------------------------------------------------------------------------------
if (with-console)
    add_executable( bx
        "console/libbitcoin.ico"
        "console/main.cpp" )

#     bx project specific include directories.
#------------------------------------------------------------------------------
    target_include_directories( bx PRIVATE
        "include" )

#     bx project specific libraries/linker flags.
#------------------------------------------------------------------------------
    target_link_libraries( bx
        ${PROJECT_NAME} )

endif()

# Define libbitcoin-system-test project.
#------------------------------------------------------------------------------
if (with-tests)
    add_executable( ${PROJECT_NAME}-test
        "test/generated__broadcast.cpp"
        "test/generated__find.cpp"
        "test/generated__formerly.cpp"
        "test/generated__symbol.cpp"
        "test/main.cpp"
        "test/commands/address-decode.cpp"
        "test/commands/address-embed.cpp"
        "test/commands/address-encode.cpp"
        "test/commands/address-to-key.cpp"
        "test/commands/base16-decode.cpp"
        "test/commands/base16-encode.cpp"
        "test/commands/base58-decode.cpp"
        "test/commands/base58-encode.cpp"
        "test/commands/base58check-decode.cpp"
        "test/commands/base58check-encode.cpp"
        "test/commands/base64-decode.cpp"
        "test/commands/base64-encode.cpp"
        "test/commands/bitcoin160.cpp"
        "test/commands/bitcoin256.cpp"
        "test/commands/btc-to-satoshi.cpp"
        "test/commands/cert-new.cpp"
        "test/commands/cert-public.cpp"
        "test/commands/command.hpp"
        "test/commands/ec-add-secrets.cpp"
        "test/commands/ec-add.cpp"
        "test/commands/ec-decompress.cpp"
        "test/commands/ec-multiply-secrets.cpp"
        "test/commands/ec-multiply.cpp"
        "test/commands/ec-new.cpp"
        "test/commands/ec-to-address.cpp"
        "test/commands/ec-to-ek.cpp"
        "test/commands/ec-to-public.cpp"
        "test/commands/ec-to-wif.cpp"
        "test/commands/ek-address.cpp"
        "test/commands/ek-new.cpp"
        "test/commands/ek-public-to-address.cpp"
        "test/commands/ek-public-to-ec.cpp"
        "test/commands/ek-public.cpp"
        "test/commands/ek-to-address.cpp"
        "test/commands/ek-to-ec.cpp"
        "test/commands/electrum-new.cpp"
        "test/commands/electrum-to-seed.cpp"
        "test/commands/fetch-balance.cpp"
        "test/commands/fetch-block.cpp"
        "test/commands/fetch-header.cpp"
        "test/commands/fetch-height.cpp"
        "test/commands/fetch-history.cpp"
        "test/commands/fetch-public-key.cpp"
        "test/commands/fetch-stealth.cpp"
        "test/commands/fetch-tx-index.cpp"
        "test/commands/fetch-tx.cpp"
        "test/commands/fetch-utxo.cpp"
        "test/commands/hd-new.cpp"
        "test/commands/hd-private.cpp"
        "test/commands/hd-public.cpp"
        "test/commands/hd-to-address.cpp"
        "test/commands/hd-to-ec.cpp"
        "test/commands/hd-to-public.cpp"
        "test/commands/hd-to-wif.cpp"
        "test/commands/help.cpp"
        "test/commands/input-set.cpp"
        "test/commands/input-sign.cpp"
        "test/commands/input-validate.cpp"
        "test/commands/message-sign.cpp"
        "test/commands/message-validate.cpp"
        "test/commands/mnemonic-decode.cpp"
        "test/commands/mnemonic-encode.cpp"
        "test/commands/mnemonic-new.cpp"
        "test/commands/mnemonic-to-seed.cpp"
        "test/commands/qrcode.cpp"
        "test/commands/ripemd160.cpp"
        "test/commands/satoshi-to-btc.cpp"
        "test/commands/script-decode.cpp"
        "test/commands/script-encode.cpp"
        "test/commands/script-to-address.cpp"
        "test/commands/script-to-key.cpp"
        "test/commands/seed.cpp"
        "test/commands/send-tx-node.cpp"
        "test/commands/send-tx-p2p.cpp"
        "test/commands/send-tx.cpp"
        "test/commands/settings.cpp"
        "test/commands/sha160.cpp"
        "test/commands/sha256.cpp"
        "test/commands/sha512.cpp"
        "test/commands/stealth-decode.cpp"
        "test/commands/stealth-encode.cpp"
        "test/commands/stealth-public.cpp"
        "test/commands/stealth-secret.cpp"
        "test/commands/stealth-shared.cpp"
        "test/commands/subscribe-block.cpp"
        "test/commands/subscribe-tx.cpp"
        "test/commands/token-new.cpp"
        "test/commands/tx-decode.cpp"
        "test/commands/tx-encode.cpp"
        "test/commands/tx-sign.cpp"
        "test/commands/uri-decode.cpp"
        "test/commands/uri-encode.cpp"
        "test/commands/validate-tx.cpp"
        "test/commands/watch-key.cpp"
        "test/commands/watch-stealth.cpp"
        "test/commands/watch-tx.cpp"
        "test/commands/wif-to-ec.cpp"
        "test/commands/wif-to-public.cpp"
        "test/commands/wrap-decode.cpp"
        "test/commands/wrap-encode.cpp"
        "test/config/address.cpp" )

    add_test( NAME ${PROJECT_NAME}-test COMMAND ${PROJECT_NAME}-test
            --run_test=generated,obsolete,offline,config,stub
            --show_progress=no
            --detect_memory_leak=0
            --report_level=no
            --build_info=yes )

#     libbitcoin-system-test project specific include directories.
#------------------------------------------------------------------------------
    target_include_directories( ${PROJECT_NAME}-test PRIVATE
        "include" )

#     libbitcoin-system-test project specific libraries/linker flags.
#------------------------------------------------------------------------------
    target_link_libraries( ${PROJECT_NAME}-test
        ${PROJECT_NAME}
        Boost::unit_test_framework )
endif()




set(pc_config "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}.pc")
configure_file(${PROJECT_NAME}.pc.in ${pc_config} @ONLY)

#set(la_config "${CMAKE_CURRENT_BINARY_DIR}/lib${PROJECT_NAME}.la")
#configure_file(${PROJECT_NAME}.la.in ${la_config} @ONLY)

# Installation (https://github.com/forexample/package-example) {

set(config_install_dir "lib/cmake/${PROJECT_NAME}")
set(include_install_dir "include")

set(generated_dir "${CMAKE_CURRENT_BINARY_DIR}/generated")

set(version_config "${generated_dir}/${PROJECT_NAME}ConfigVersion.cmake")
set(project_config "${generated_dir}/${PROJECT_NAME}Config.cmake")
set(TARGETS_EXPORT_NAME "${PROJECT_NAME}Targets")
set(namespace "${PROJECT_NAME}::")

include(CMakePackageConfigHelpers)

# Use:
#   * PROJECT_VERSION
write_basic_package_version_file(
    "${version_config}" COMPATIBILITY SameMajorVersion
)

# Use variables:
#   * TARGETS_EXPORT_NAME
#   * PROJECT_NAME
configure_package_config_file(
    "cmake/Config.cmake.in"
    "${project_config}"
    INSTALL_DESTINATION "${config_install_dir}"
)

install(
    TARGETS ${PROJECT_NAME}
    EXPORT "${TARGETS_EXPORT_NAME}"
    LIBRARY DESTINATION "lib"
    ARCHIVE DESTINATION "lib"
    RUNTIME DESTINATION "bin"
    INCLUDES DESTINATION "${include_install_dir}"
)

install(
    DIRECTORY include/
    DESTINATION "${include_install_dir}"
)

install(
    FILES "${project_config}" "${version_config}"
    DESTINATION "${config_install_dir}"
)

install(
    EXPORT "${TARGETS_EXPORT_NAME}"
    NAMESPACE "${namespace}"
    DESTINATION "${config_install_dir}"
)

install(FILES ${pc_config} DESTINATION lib/pkgconfig)
install(FILES ${la_config} DESTINATION lib)
