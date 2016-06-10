#!/usr/bin/env bash

set -euo pipefail

readonly binPath=$1

function main
{
  test -f $binPath/faust
}

main "$@"

