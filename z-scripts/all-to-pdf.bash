#!/bin/bash
DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"
shopt -s globstar
cd ..
$DIR/folder-to-pdf.bash **/homework . week* x*
