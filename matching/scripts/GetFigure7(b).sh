#!/bin/bash
echo "=================snort24===================="
echo "Raibow"
echo "============================================"
../rainbow/build/rainbow  ../../datasets/Brotli/Alexa/decompressed/ ../../datasets/Brotli/Alexa/decoded/ ../../tables/snort24.txt ../../tables/snort24-accept.txt 1
echo "Twins"
echo "============================================"
../twins/build/twins  ../../datasets/Gzip/Alexa/decoded ../../tables/snort24.txt ../../tables/snort24-accept.txt 1
echo "Naive"
echo "============================================"
../naive/build/naive  ../../datasets/Brotli/Alexa/decompressed/ ../../tables/snort24.txt ../../tables/snort24-accept.txt 1


echo "=================snort31===================="

echo "Raibow"
echo "============================================"
../rainbow/build/rainbow  ../../datasets/Brotli/Alexa/decompressed/ ../../datasets/Brotli/Alexa/decoded/ ../../tables/snort31.txt ../../tables/snort31-accept.txt 1
echo "============================================"
echo "Twins"
echo "============================================"
../twins/build/twins  ../../datasets/Gzip/Alexa/decoded ../../tables/snort31.txt ../../tables/snort31-accept.txt 1
echo "============================================"
echo "Naive"
echo "============================================"
../naive/build/naive  ../../datasets/Brotli/Alexa/decompressed/ ../../tables/snort31.txt ../../tables/snort31-accept.txt 1


echo "=================snort34===================="

echo "Raibow"
echo "============================================"
../rainbow/build/rainbow  ../../datasets/Brotli/Alexa/decompressed/ ../../datasets/Brotli/Alexa/decoded/ ../../tables/snort34.txt ../../tables/snort34-accept.txt 1
echo "============================================"
echo "============================================"
echo "Twins"
echo "============================================"
../twins/build/twins  ../../datasets/Gzip/Alexa/decoded ../../tables/snort34.txt ../../tables/snort34-accept.txt 1
echo "============================================"
echo "Naive"
echo "============================================"
../naive/build/naive  ../../datasets/Brotli/Alexa/decompressed/ ../../tables/snort34.txt ../../tables/snort34-accept.txt 1
