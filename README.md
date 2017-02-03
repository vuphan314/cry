# Cry
cryptographic framework

## links
- projects
  - 1 (project plan)
    - [presentation][presentation1]
    - [report][report1]
- [releases][releases]

## convention
preferred max line length: 60-character

## contribution
```
git checkout https://github.com/vuphan314/cry
cd cry/
git branch -a
git checkout <your_branch>
```
- make change, commit, push
- create a pull request on GitHub
  from `<your_branch>` to `master`

## TeX

### macros
see `newcommand` lines in file `cry.sty`

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
<!-- --------------------------------------------------- -->

[presentation1]:https://github.com/vuphan314/cry/blob/master/project1/presentation/presentation.pdf
[report1]:https://github.com/vuphan314/cry/blob/master/project1/report/report.pdf

[releases]:https://github.com/vuphan314/cry/releases
