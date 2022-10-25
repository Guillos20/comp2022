#!/bin/bash

echo "Deleting old lex and yacc files"
make clean
echo "Deleting old zip file..."
rm -f jucompiler.zip
echo "Creating new zip file..."
zip /jucompiler *