#!/bin/bash
cp ../rainbow/build/rainbow ../../datasets/Brotli/Enwik/compressed
cp ../naive/build/naive ../../datasets/Brotli/Enwik/compressed
cp ../twins/build/twins ../../datasets/Gzip/Enwik/
echo "========================================="


cd ../../datasets/Brotli/Enwik/compressed
echo "Rainbow"
./rainbow -t enwik8.br
echo "complete!"
rm -rf ./rainbow


echo "========================================="
echo "Twins"
cd ../../../Gzip/Enwik/
./twins ../../../datasets/Gzip/Enwik/compressed
echo "complete!"
rm -rf ./twins

echo "========================================="
echo "Naive"
cd ../../Brotli/Enwik/compressed
./naive -t enwik8.br
echo "complete!"
rm -rf ./naive
echo "========================================="

