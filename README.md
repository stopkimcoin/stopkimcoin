Specifications
* Ticker: STKC
* Premine: ~2.5%
* Mining algorithm: CryptoNight (it enables truly anonymous and decentralized blockchain-based currency)
* Max supply: 100 million coins
* Block reward: initial reward of ~190 STKC
* Block target time: 60 seconds
* Difficulty: Retargets at every block
* Transaction fee: 0.001 STKC
* P2P Port: 44211
* RPC Port: 44212

Community
* Twitter: https://twitter.com/stopkimcoin
* Telegram:  
Website: coming soon

Mining pools: coming soon

Block explorer: coming soon

Wallets

Windows GUI wallet: coming soon

Linux GUI wallet:
  
Instructions
* Decompress the file: tar -zxvf stopkimcoin.tar.gz
* Run the executable: ./stopkimcoin
* Write down your seed information in case you lose your wallet!

Pre-compiled binaries:

For Linux:
 
 Instructions (Tested on Ubuntu 16.0)
* Extract the files: tar -zxvf stopkimcoin_linux_x64_bin.tar.gz
* Run ./stopkimcoind to synchronize your computer with the P2P network blockchain, then keep the program running
* Open a new terminal and run ./simplewallet to create/open your wallet
* Write down your seed information in case you lose your wallet!

You can also compile directly from the source code:

For Linux:

Linux Instructions:
* Build your environment ~$ sudo apt-get update ~$ sudo apt-get install build-essential git cmake libboost-all-dev
* Download stopkimcoin source code ~$ git clone ?https://github.com/stopkimcoin/stopkimcoin.git
* Build the binaries ~$ cd stopkimcoin ~/stopkimcoin$ make
* Sync the blockchain ~/stopkimcoin$ cd build/release/src/ ~/stopkimcoin/build/release/src$ ./stopkimcoind --log-level=3
* Create your wallet (open it in a new terminal because you need the stopkimcoin daemon running) ~/stopkimcoin/build/release/src$ ./simplewallet
* Write down your seed information in case you lose your wallet!
* Start mining your coins! Type start_mining. For more commands, type help.

Windows Instructions:
* Install Microsoft Visual Studio Community 2015
* Install the latest CMake:
o During installation, choose Add cmake to your system path
* Download and compile Boost 1.60.0 C++ Libraries: https://sourceforge.net/projects/boost/files/boost/1.60.0/boost_1_60_0.zip/download
o Extract the zip archive
o Compile Boost 1.60.0
o Run Windows command prompt cmd
o cd to where you extracted boost__1_60_0
o Run bootstrap.bat
o Run b2 --toolset=msvc variant=release link=static threading=multi runtime-link=static address-model=64
* Download stopkimcoin source code to your computer
o Clone repository type git clone https://github.com/stopkimcoin/stopkimcoin.git
* Finally, compile stopkimcoin
o cd stopkimcoin
o mkdir build -- Create 'build' directory.
o cd build -- Change to build Directory.
o cmake -G "Visual Studio 15 Win64" -DBOOST_ROOT=c:\boost_1_60_0 
-DBOOST_LIBRARY_DIR=c:\boost_1_60_0\stage\lib ..
o msbuild stopkimcoin.sln /p:Configuration=release
Find your binaries in ..\stopkimcoin\build\src\release\

Good luck everyone!

