#!/bin/bash
echo "=================snort24===================="
echo "Raibow"
echo "============================================"
../rainbow/build/rainbow  ../../datasets/Brotli/Enwik/decompressed/ ../../datasets/Brotli/Enwik/decoded/ ../../tables/snort24.txt ../../tables/snort24-accept.txt 3
echo "Twins"
echo "============================================"
../twins/build/twins  ../../datasets/Gzip/Enwik/decoded ../../tables/snort24.txt ../../tables/snort24-accept.txt 3
echo "Naive"
echo "============================================"
../naive/build/naive  ../../datasets/Brotli/Enwik/decompressed/ ../../tables/snort24.txt ../../tables/snort24-accept.txt 3


echo "=================snort31===================="

echo "Raibow"
echo "============================================"
../rainbow/build/rainbow  ../../datasets/Brotli/Enwik/decompressed/ ../../datasets/Brotli/Enwik/decoded/ ../../tables/snort31.txt ../../tables/snort31-accept.txt 3
echo "============================================"
echo "Twins"
echo "============================================"
../twins/build/twins  ../../datasets/Gzip/Enwik/decoded ../../tables/snort31.txt ../../tables/snort31-accept.txt 3
echo "============================================"
echo "Naive"
echo "============================================"
../naive/build/naive  ../../datasets/Brotli/Enwik/decompressed/ ../../tables/snort31.txt ../../tables/snort31-accept.txt 3


echo "=================snort34===================="

echo "Raibow"
echo "============================================"
../rainbow/build/rainbow  ../../datasets/Brotli/Enwik/decompressed/ ../../datasets/Brotli/Enwik/decoded/ ../../tables/snort34.txt ../../tables/snort34-accept.txt 3
echo "============================================"
echo "============================================"
echo "Twins"
echo "============================================"
../twins/build/twins  ../../datasets/Gzip/Enwik/decoded ../../tables/snort34.txt ../../tables/snort34-accept.txt 3
echo "============================================"
echo "Naive"
echo "============================================"
../naive/build/naive  ../../datasets/Brotli/Enwik/decompressed/ ../../tables/snort34.txt ../../tables/snort34-accept.txt 3
