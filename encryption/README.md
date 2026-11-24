# Encryption

Educational DES block encryption/decryption and small-integer RSA examples.

## Demos

| Executable | Demonstration |
| --- | --- |
| `enc` | Encrypt and decrypt an 8-byte DES block, check its expected ciphertext, and verify an RSA round trip |

## Build and run

Requires a C11 compiler and Make on macOS or Linux. From the repository root:

```sh
cd encryption
make
./enc
make clean
```

No arguments or input are required. Expected output:

```text
DES ciphertext: 85 e8 13 54 0f 0a b4 05
DES round trip passed
RSA: 65 -> 2790 -> 65
```

## Notes

- These are learning examples, not production cryptography. DES is obsolete, and RSA here uses tiny keys, no padding, and native `unsigned long` arithmetic. Large RSA inputs can overflow.
- Run `make check` or `make check-sanitize` from the repository root to build and exercise all portable demos.
