cmake_minimum_required(VERSION 2.8)

include(CryptoNoteWallet.cmake)
include(QREncode.cmake)

project(${CN_PROJECT_NAME})

execute_process(COMMAND git log -1 --pretty=format:%h
WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
OUTPUT_VARIABLE GIT_REVISION)

set(CRYPTONOTE_LIB cryptonote)
set (CMAKE_PREFIX_PATH "C:\\Qt\\Qt5.6.0\\5.6\\msvc2013_64\\")

include_directories(${CMAKE_BINARY_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}
    src
    cryptonote/class
    cryptonote/modules
    cryptonote/include
    cryptonote/src)

find_package(Qt5Gui REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Network REQUIRED)

set(Boost_USE_STATIC_LIBS ON)
if(WIN32)
  set(Boost_USE_STATIC_RUNTIME OFF)
else(WIN32)
  set(Boost_USE_STATIC_RUNTIME ON)
endif(WIN32)

find_package(Boost 1.55 REQUIRED COMPONENTS date_time filesystem program_options regex serialization system thread chrono)
if ((${Boost_MAJOR_VERSION} EQUAL 1) AND (${Boost_MINOR_VERSION} EQUAL 54))
	message(SEND_ERROR "Boost version 1.54 is unsupported, more details are available here http://goo.gl/RrCFmA")
endif ()

include_directories(${Boost_INCLUDE_DIRS})
link_directories(${Boost_LIBRARY_DIRS})

set(VERSION "")
configure_file("cryptonote/src/version.h.in" "version.h")
configure_file("src/CryptoNoteWalletConfig.h.in" "CryptoNoteWalletConfig.h")

add_definitions(-DVERSION=\"${CN_VERSION}\")
add_definitions(-DGIT_REVISION=\"${GIT_REVISION}\")

set(CMAKE_AUTOMOC ON)

set(CRYPTONOTE_SOURCES
  cryptonote/modules/miniupnpc/connecthostport.c
  cryptonote/modules/miniupnpc/igd_desc_parse.c
  cryptonote/modules/miniupnpc/minisoap.c
  cryptonote/modules/miniupnpc/miniupnpc.c
  cryptonote/modules/miniupnpc/miniwget.c
  cryptonote/modules/miniupnpc/minixml.c
  cryptonote/modules/miniupnpc/portlistingparse.c
  cryptonote/modules/miniupnpc/receivedata.c
  cryptonote/modules/miniupnpc/upnpcommands.c
  cryptonote/modules/miniupnpc/upnpreplyparse.c
  cryptonote/src/common/Base58.cpp
  cryptonote/src/common/CommandLine.cpp
  cryptonote/src/common/Util.cpp
  cryptonote/src/common/StringTools.cpp
  cryptonote/src/common/JsonValue.cpp
  cryptonote/src/common/ConsoleTools.cpp
  cryptonote/src/common/MemoryInputStream.cpp
  cryptonote/src/common/PathTools.cpp
  cryptonote/src/common/StdInputStream.cpp
  cryptonote/src/common/StdOutputStream.cpp
  cryptonote/src/common/StreamTools.cpp
  cryptonote/src/common/StringOutputStream.cpp
  cryptonote/src/common/StringView.cpp
  cryptonote/src/common/VectorOutputStream.cpp
  cryptonote/src/crypto/blake256.c
  cryptonote/src/crypto/chacha8.c
  cryptonote/src/crypto/crypto-ops-data.c
  cryptonote/src/crypto/crypto-ops.c
  cryptonote/src/crypto/crypto.cpp
  cryptonote/src/crypto/groestl.c
  cryptonote/src/crypto/hash-extra-blake.c
  cryptonote/src/crypto/hash-extra-groestl.c
  cryptonote/src/crypto/hash-extra-jh.c
  cryptonote/src/crypto/hash-extra-skein.c
  cryptonote/src/crypto/hash.c
  cryptonote/src/crypto/jh.c
  cryptonote/src/crypto/keccak.c
  cryptonote/src/crypto/oaes_lib.c
  cryptonote/src/crypto/random.c
  cryptonote/src/crypto/skein.c
  cryptonote/src/crypto/slow-hash.c
  cryptonote/src/crypto/slow-hash.cpp
  cryptonote/src/crypto/tree-hash.c
  cryptonote/src/core/block/BlockchainIndices.cpp
  cryptonote/src/core/block/BlockchainMessages.cpp
  cryptonote/src/core/block/BlockIndex.cpp
  cryptonote/src/core/CoreConfig.cpp
  cryptonote/src/base/CryptoNoteBasic.cpp
  cryptonote/src/base/CryptoNoteTools.cpp
  cryptonote/src/core/Currency.cpp
  cryptonote/src/core/DepositIndex.cpp
  cryptonote/src/core/mine/MinerConfig.cpp
  cryptonote/src/core/trans/Transaction.cpp
  cryptonote/src/core/Account.cpp
  cryptonote/src/core/block/Blockchain.cpp
  cryptonote/src/core/Checkpoints.cpp
  cryptonote/src/base/CryptoNoteBasicImpl.cpp
  cryptonote/src/core/Core.cpp
  cryptonote/src/base/CryptoNoteFormatUtils.cpp
  cryptonote/src/base/CryptoNoteSerialization.cpp
  cryptonote/src/core/Difficulty.cpp
  cryptonote/src/seria/IBlock.cpp
  cryptonote/src/core/mine/Miner.cpp
  cryptonote/src/core/trans/TransactionExtra.cpp
  cryptonote/src/core/trans/TransactionPool.cpp
  cryptonote/src/core/trans/TransactionPrefixImpl.cpp
  cryptonote/src/core/trans/TransactionUtils.cpp
  cryptonote/src/procnode/InProcessNode.cpp
  cryptonote/src/procnode/InProcessNodeErrors.cpp
  cryptonote/src/node_rpc_proxy/NodeErrors.cpp
  cryptonote/src/node_rpc_proxy/NodeRpcProxy.cpp
  cryptonote/src/p2p/NetNodeConfig.cpp
  cryptonote/src/Serialization/BinaryInputStreamSerializer.cpp
  cryptonote/src/Serialization/BinaryOutputStreamSerializer.cpp
  cryptonote/src/Serialization/JsonInputValueSerializer.cpp
  cryptonote/src/Serialization/JsonOutputStreamSerializer.cpp
  cryptonote/src/Serialization/KVBinaryInputStreamSerializer.cpp
  cryptonote/src/Serialization/KVBinaryOutputStreamSerializer.cpp
  cryptonote/src/Serialization/SerializationOverloads.cpp
  cryptonote/src/transfers/BlockchainSynchronizer.cpp
  cryptonote/src/transfers/SynchronizationState.cpp
  cryptonote/src/transfers/TransfersConsumer.cpp
  cryptonote/src/transfers/TransfersContainer.cpp
  cryptonote/src/transfers/TransfersSubscription.cpp
  cryptonote/src/transfers/TransfersSynchronizer.cpp
  cryptonote/src/wallet/LegacyKeysImporter.cpp
  cryptonote/src/wallet/WalletAsyncContextCounter.cpp
  cryptonote/src/wallet/WalletErrors.cpp
  cryptonote/src/wallet_legacy/KeysStorage.cpp
  cryptonote/src/wallet_legacy/WalletLegacy.cpp
  cryptonote/src/wallet_legacy/WalletHelper.cpp
  cryptonote/src/wallet_legacy/WalletLegacySerializer.cpp
  cryptonote/src/wallet_legacy/WalletLegacySerialization.cpp
  cryptonote/src/wallet_legacy/WalletTransactionSender.cpp
  cryptonote/src/wallet_legacy/WalletUnconfirmedTransactions.cpp
  cryptonote/src/wallet_legacy/WalletUserTransactionsCache.cpp
  cryptonote/src/System/ContextGroup.cpp
  cryptonote/src/System/Event.cpp
  cryptonote/src/System/EventLock.cpp
  cryptonote/src/System/InterruptedException.cpp
  cryptonote/src/System/Ipv4Address.cpp
  cryptonote/src/System/TcpStream.cpp
  cryptonote/src/http/HttpRequest.cpp
  cryptonote/src/http/HttpParser.cpp
  cryptonote/src/http/HttpParserErrorCodes.cpp
  cryptonote/src/http/HttpResponse.cpp
  cryptonote/src/rpc/HttpClient.cpp
  cryptonote/src/rpc/JsonRpc.cpp
  cryptonote/src/p2p/NetNode.cpp
  cryptonote/src/p2p/LevinProtocol.cpp
  cryptonote/src/p2p/NetNodeConfig.cpp
  cryptonote/src/p2p/PeerListManager.cpp
  cryptonote/src/protocol/CryptoNoteProtocolHandler.cpp
  cryptonote/src/seria/ILogger.cpp
  cryptonote/src/log/LoggerGroup.cpp
  cryptonote/src/log/CommonLogger.cpp
  cryptonote/src/log/LoggerManager.cpp
  cryptonote/src/log/FileLogger.cpp
  cryptonote/src/log/StreamLogger.cpp
  cryptonote/src/log/ConsoleLogger.cpp
  cryptonote/src/log/LoggerMessage.cpp
  cryptonote/src/log/LoggerRef.cpp
  cryptonote/src/blockchain_explorer/BlockchainExplorer.cpp
  cryptonote/src/blockchain_explorer/BlockchainExplorerDataBuilder.cpp
  cryptonote/src/blockchain_explorer/BlockchainExplorerErrors.cpp
)

file(GLOB_RECURSE SOURCES src/*.cpp)
file(GLOB_RECURSE HEADERS src/*.h)
file(GLOB_RECURSE FORMS src/gui/ui/*.ui)

set(QRC src/resources.qrc)

qt5_wrap_ui(UIS ${FORMS})
qt5_add_resources(RCC ${QRC})


if (WIN32)
  if (NOT MSVC)
	message(FATAL_ERROR "Only MSVC is supported on this platform")
  endif ()
  add_definitions(/D_CRT_SECURE_NO_WARNINGS /D_WIN32_WINNT=0x0600 /DSTATICLIB)
  include_directories(cryptonote/src/platform/msc)

  set(PLATFORM_DIR Windows)
  set(BUILD_PLATFORM WIN32)
  set(BUILD_RESOURCES src/cryptonotewallet.rc)
  set(QTMAIN Qt5::WinMain)

elseif (UNIX)
  set(CRYPTONOTE_SOURCES ${CRYPTONOTE_SOURCES} cryptonote/modules/miniupnpc/minissdpc.c)
  if (APPLE)
    enable_language(ASM)
    file(GLOB_RECURSE OBJC_SOURCES src/*.mm)
    set(SOURCES ${SOURCES} ${OBJC_SOURCES})
    set(PLATFORM_DIR OSX)
    set(MACOSX_BUNDLE_INFO_STRING "Cryptonote GUI wallet")
    set(MACOSX_BUNDLE_LONG_VERSION_STRING "${VERSION_VERSION}.${VERSION_MINOR}.${VERSION_PATCH}")
    set(MACOSX_BUNDLE_BUNDLE_NAME CryptonoteWallet)
    set(MACOSX_BUNDLE_SHORT_VERSION_STRING "${VERSION_VERSION}.${VERSION_MINOR}.${VERSION_PATCH}")
    set(MACOSX_BUNDLE_BUNDLE_VERSION "$${VERSION_VERSION}.${VERSION_MINOR}.${VERSION_PATCH}")

    find_package(Qt5PrintSupport REQUIRED)

    include_directories(/usr/include/malloc)

    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -maes -std=c++11 -stdlib=libc++")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11 -maes -D_DARWIN_C_SOURCE")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -framework Cocoa -framework OpenGL -framework CoreFoundation -framework Carbon -framework IOKit -L/usr/lib")

    set(MACOSX_BUNDLE_ICON_FILE cryptonote.icns)
    set(APPLICATION_ICON src/images/cryptonote.icns)
    set_source_files_properties(${APPLICATION_ICON} PROPERTIES MACOSX_PACKAGE_LOCATION "Resources")

    set(BUILD_PLATFORM MACOSX_BUNDLE)
    set(BUILD_RESOURCES ${APPLICATION_ICON})
	
    GET_TARGET_PROPERTY(QT_LIB_DIR "${Qt5Widgets_LIBRARIES}" LOCATION)
    GET_FILENAME_COMPONENT(QT_LIB_DIR "${QT_LIB_DIR}" PATH)
  else(APPLE)
    set(PLATFORM_DIR Linux)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -maes -std=c++11")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -maes -std=c11")
  endif (APPLE)
endif ()

include_directories(cryptonote/src/Platform/${PLATFORM_DIR})
file(GLOB PLATFORM_SOURCES cryptonote/src/Platform/${PLATFORM_DIR}/System/*)
set(CRYPTONOTE_SOURCES ${CRYPTONOTE_SOURCES} ${PLATFORM_SOURCES})

add_library(${CRYPTONOTE_LIB} STATIC ${CRYPTONOTE_SOURCES})
set_target_properties(${CRYPTONOTE_LIB} PROPERTIES COMPILE_DEFINITIONS _GNU_SOURCE)
target_link_libraries(${CRYPTONOTE_LIB} ${Boost_LIBRARIES})

add_executable(${PROJECT_NAME} ${BUILD_PLATFORM} ${BUILD_RESOURCES} ${SOURCES} ${HEADERS} ${UIS} ${RCC})
set_target_properties(${PROJECT_NAME} PROPERTIES COMPILE_DEFINITIONS _GNU_SOURCE)
target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES} ${QTMAIN} ${CRYPTONOTE_LIB} ${QRENCODE_LIB})

if (APPLE)
  qt5_use_modules(${PROJECT_NAME} PrintSupport)
elseif (UNIX)
  target_link_libraries(${PROJECT_NAME} -lpthread)
elseif (WIN32)
  target_link_libraries(${PROJECT_NAME} Imm32 Iphlpapi Winmm)
endif (APPLE)

qt5_use_modules(${PROJECT_NAME} Widgets Gui Network)

# Installation

set(CPACK_PACKAGE_NAME ${CN_PROJECT_NAME})
set(CPACK_PACKAGE_VERSION ${CN_VERSION})
set(CPACK_PACKAGE_VENDOR "Catalyst Foundation")
set(CPACK_PACKAGE_CONTACT "https://catalyst.cash/")
set(CPACK_STRIP_FILES ON)
if (APPLE)
    set(CPACK_GENERATOR DragNDrop)
    install(TARGETS ${PROJECT_NAME} BUNDLE DESTINATION .)
    set(CPACK_PACKAGE_FILE_NAME "${CPACK_PACKAGE_NAME}-${CPACK_PACKAGE_VERSION}.-${VERSION_RELEASE}")
elseif (UNIX)
    install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)
    install(FILES src/catawallet.desktop DESTINATION share/applications)
    install(FILES src/images/cryptonote.png DESTINATION share/pixmaps RENAME cata.png)
    install(FILES copyright DESTINATION share/doc/catawallet)

	SET(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE")
	SET(CPACK_PACKAGE_DESCRIPTION_FILE "${CMAKE_CURRENT_SOURCE_DIR}/README.md")
	SET(CPACK_PACKAGE_ICON src/images/cryptonote.png)
	
    if (NOT PACKRPM)
        set(CPACK_GENERATOR DEB)
        set(CPACK_DEBIAN_PACKAGE_NAME ${CPACK_PACKAGE_NAME})
        set(CPACK_SYSTEM_NAME amd64)
        set(CPACK_DEBIAN_PACKAGE_MAINTAINER "${CPACK_PACKAGE_VENDOR} <xrydev@gmail.com>")
        set(CPACK_DEBIAN_PACKAGE_SECTION Office)
        set(CPACK_DEBIAN_PACKAGE_SHLIBDEPS ON)
        set(CPACK_DEBIAN_PACKAGE_DESCRIPTION "Catalyst is payment processor faster transaction. And more features on.
 .
 Features of the Catalyst wallet listed bellow:
 * Classic Bitcoin alike appearance in CryptoNote based cryptocurrency,
   made with QT and open-source.
 * Instant CALT transfers and transfers notifications
 * Safe and secure, full Catalyst network node in wallet, fast network
   syncronization.
 * Wallet encryption
 * Fast and hardware optimized
 * Payment For all merchant[Halal product]
 * Open and easy. Private keys can be exported into other clients.")
set(CPACK_PACKAGE_FILE_NAME "${CPACK_DEBIAN_PACKAGE_NAME}-${CPACK_PACKAGE_VERSION}-${VERSION_RELEASE}.${CPACK_SYSTEM_NAME}")
	else ()
        set(CPACK_GENERATOR RPM)
        set(CPACK_SYSTEM_NAME x86_64)
        set(CPACK_RPM_PACKAGE_RELEASE ${VERSION_RELEASE})
        set(CPACK_RPM_PACKAGE_LICENSE "GPL3")
        set(CPACK_RPM_PACKAGE_GROUP Office)
        set(CPACK_RPM_PACKAGE_REQUIRES "qt5-qtbase >= 5.3.2, qt5-qtbase-gui >= 5.3.2")
        set(CPACK_RPM_PACKAGE_SUMMARY "Catalyst wallet")
        set(CPACK_RPM_PACKAGE_DESCRIPTION "Catalyst is payment processor faster transaction. And more features on.

 Features of the Catalyst wallet listed bellow:
 * Classic Bitcoin alike appearance in CryptoNote based cryptocurrency,
   made with QT and open-source.
 * Instant CALT transfers and transfers notifications
 * Safe and secure, full Catalyst network node in wallet, fast network
   syncronization.
 * Wallet encryption
 * Fast and hardware optimized
 * Payment For all merchant[Halal product]
 *Open and easy. Private keys can be exported into other clients.")
set(CPACK_PACKAGE_FILE_NAME "${CPACK_PACKAGE_NAME}-${CPACK_PACKAGE_VERSION}-${VERSION_RELEASE}.${CPACK_SYSTEM_NAME}")
    endif ()
elseif (WIN32)
  install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION .)
  set(CPACK_GENERATOR ZIP)
endif (APPLE)

include(CPack)
