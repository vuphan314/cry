# demo

## general use
`./main.sh`

## example
`make -C ../src/ && cp ../src/cry .`

### key-generation by receiver `michael`
- `./cry g michael rsa 46`
  - OVERWRITING FILES:
    - `michael.public`
    - `michael.private` (git-ignored)
- git-add/commit/push

### encryption by sender `daniel`
- git-pull
- write plaintext in file `daniel.private` (git-ignored)
- `./cry e daniel michael`
  - OVERWRITING FILE `daniel.public`
- git-add/commit/push

### decryption by receiver `michael`
- git-pull
- `./cry d michael daniel`

### cryptanalysis
- git-pull
- `./cry d michael daniel`
