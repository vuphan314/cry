# Cry
cryptographic framework

## convention
preferred max line length: 60-character

## TeX

### online
- https://www.overleaf.com/
- multiple `tex` files to one `pdf` file
- no account needed

### offline
- installation
  ```
  sudo apt install texlive-full

  ```
- compilation
  - `Atom`: https://atom.io/packages/latex
  - `Terminal`
    ```
    cd project1/presentation/

    latexmk -pdf -synctex=1 presentation.tex

    ```
