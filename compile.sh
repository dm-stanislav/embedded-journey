#!/usr/bin/env bash
set -euo pipefail

usage() {
  printf 'Usage: %s [-r|--run] <file.c>\n' "$(basename "$0")" >&2
  printf '  Compiles to build/<path-without-.c> (mirrors source dirs under this project).\n' >&2
  printf '  -r, --run   Run the built binary after a successful compile.\n' >&2
}

SCRIPT_DIR=$(cd "$(dirname "$0")" && pwd)
RUN_AFTER=0

while [ $# -gt 0 ]; do
  case "$1" in
    -r | --run)
      RUN_AFTER=1
      shift
      ;;
    -h | --help)
      usage
      exit 0
      ;;
    --)
      shift
      break
      ;;
    -*)
      printf 'Unknown option: %s\n' "$1" >&2
      usage
      exit 1
      ;;
    *)
      break
      ;;
  esac
done

if [ $# -ne 1 ]; then
  usage
  exit 1
fi

SRC=$1
case "$SRC" in
  *.c) ;;
  *)
    printf 'Expected a .c source file, got: %s\n' "$SRC" >&2
    exit 1 ;;
esac

SRC_ABS=$(realpath "$SRC")
case "$SRC_ABS" in
  "$SCRIPT_DIR"/*) ;;
  *)
    printf 'Source must be under project root:\n  %s\n' "$SCRIPT_DIR" >&2
    exit 1
    ;;
esac

REL=${SRC_ABS#"$SCRIPT_DIR"/}
OUT="$SCRIPT_DIR/build/${REL%.c}"
mkdir -p "$(dirname "$OUT")"

CC=${CC:-cc}
CFLAGS=${CFLAGS:--Wall -Wextra -std=gnu11}

$CC $CFLAGS -o "$OUT" "$SRC_ABS"

if [ "$RUN_AFTER" -eq 1 ]; then
  exec "$OUT"
fi
