if [ -d "./build" ] 
then
    rm -rf build 
fi



mkdir build

cp libz.a ./build

g++ twins.cpp -o twins -O2 -lz

echo "success!"

mv twins build
