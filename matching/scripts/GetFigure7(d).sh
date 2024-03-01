#!/bin/bash
echo "=================snort24===================="
echo "Raibow"
echo "============================================"
../rainbow/build/rainbow  ../../datasets/Brotli/COVID-19/decompressed/ ../../datasets/Brotli/COVID-19/decoded/ ../../tables/snort24.txt ../../tables/snort24-accept.txt 4
echo "Twins"
echo "============================================"
../twins/build/twins  ../../datasets/Gzip/COVID-19/decoded ../../tables/snort24.txt ../../tables/snort24-accept.txt 4
echo "Naive"
echo "============================================"
../naive/build/naive  ../../datasets/Brotli/COVID-19/decompressed/ ../../tables/snort24.txt ../../tables/snort24-accept.txt 4


echo "=================snort31===================="

echo "Raibow"
echo "============================================"
../rainbow/build/rainbow  ../../datasets/Brotli/COVID-19/decompressed/ ../../datasets/Brotli/COVID-19/decoded/ ../../tables/snort31.txt ../../tables/snort31-accept.txt 4
echo "============================================"
echo "Twins"
echo "============================================"
../twins/build/twins  ../../datasets/Gzip/COVID-19/decoded ../../tables/snort31.txt ../../tables/snort31-accept.txt 4
echo "============================================"
echo "Naive"
echo "============================================"
../naive/build/naive  ../../datasets/Brotli/COVID-19/decompressed/ ../../tables/snort31.txt ../../tables/snort31-accept.txt 4


echo "=================snort34===================="

echo "Raibow"
echo "============================================"
../rainbow/build/rainbow  ../../datasets/Brotli/COVID-19/decompressed/ ../../datasets/Brotli/COVID-19/decoded/ ../../tables/snort34.txt ../../tables/snort34-accept.txt 4
echo "============================================"
echo "============================================"
echo "Twins"
echo "============================================"
../twins/build/twins  ../../datasets/Gzip/COVID-19/decoded ../../tables/snort34.txt ../../tables/snort34-accept.txt 4
echo "============================================"
echo "Naive"
echo "============================================"
../naive/build/naive  ../../datasets/Brotli/COVID-19/decompressed/ ../../tables/snort34.txt ../../tables/snort34-accept.txt 4
