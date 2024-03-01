#!/bin/bash
echo "=================snort24===================="
echo "Raibow"
echo "============================================"
../rainbow/build/rainbow  ../../datasets/Brotli/Google/decompressed/ ../../datasets/Brotli/Google/decoded/ ../../tables/snort24.txt ../../tables/snort24-accept.txt 2
echo "Twins"
echo "============================================"
../twins/build/twins  ../../datasets/Gzip/Google/decoded ../../tables/snort24.txt ../../tables/snort24-accept.txt 2
echo "Naive"
echo "============================================"
../naive/build/naive  ../../datasets/Brotli/Google/decompressed/ ../../tables/snort24.txt ../../tables/snort24-accept.txt 2


echo "=================snort31===================="

echo "Raibow"
echo "============================================"
../rainbow/build/rainbow  ../../datasets/Brotli/Google/decompressed/ ../../datasets/Brotli/Google/decoded/ ../../tables/snort31.txt ../../tables/snort31-accept.txt 2
echo "============================================"
echo "Twins"
echo "============================================"
../twins/build/twins  ../../datasets/Gzip/Google/decoded ../../tables/snort31.txt ../../tables/snort31-accept.txt 2
echo "============================================"
echo "Naive"
echo "============================================"
../naive/build/naive  ../../datasets/Brotli/Google/decompressed/ ../../tables/snort31.txt ../../tables/snort31-accept.txt 2


echo "=================snort34===================="

echo "Raibow"
echo "============================================"
../rainbow/build/rainbow  ../../datasets/Brotli/Google/decompressed/ ../../datasets/Brotli/Google/decoded/ ../../tables/snort34.txt ../../tables/snort34-accept.txt 2
echo "============================================"
echo "============================================"
echo "Twins"
echo "============================================"
../twins/build/twins  ../../datasets/Gzip/Google/decoded ../../tables/snort34.txt ../../tables/snort34-accept.txt 2
echo "============================================"
echo "Naive"
echo "============================================"
../naive/build/naive  ../../datasets/Brotli/Google/decompressed/ ../../tables/snort34.txt ../../tables/snort34-accept.txt 2
