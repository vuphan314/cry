<h6>top</h6>

# Cry
cryptographic framework

------------------------------------------------------------

## instructions

### git
- first time:
  ```
  git clone --recurse-submodules \
    https://github.com/vuphan314/cry
  cd cry/
  git branch -a
  git checkout mybranch
  ```
- each subsequent time:
  - get their changes:
    ```
    cd cry/
    git pull
    git merge origin/master
    ```
  - make my changes
  - post my changes:
    ```
    git add -A
    git commit -a -m "my commit message"
    git push
    ```
  - create GitHub pull request from `mybranch` into `master`

### C++
```
cd cry/src/
./main.sh
```

### TeX
- Atom: https://atom.io/packages/latex
- shell:
  ```
  cd cry/project3/report/
  latexmk -pdf -synctex=1 report.tex
  ```

### [GMP][gmp] on Mac OS
[Homebrew][homebrew]:
```
brew install gmp
```

### coding style
preferred max line length: 60-character

------------------------------------------------------------

## status
under development

### links
- [find files][find]
- [releases/deliverables][releases]

------------------------------------------------------------

## contributors
- [Daniel Dunning][dd]
- [Michael DeGraw][md]
- [Vu Phan][vp]

### acknowledgement
[TikZ-UML][tikzuml]: TeX package for UML diagrams

<!--------------------------------------------------------->

[gmp]:https://gmplib.org/
[homebrew]:https://brew.sh/

[find]:https://github.com/vuphan314/cry/find/master
[releases]:https://github.com/vuphan314/cry/releases
[src]:https://github.com/vuphan314/cry/tree/master/src

[dd]:https://github.com/dannydthesloth
[md]:https://github.com/electr0sheep
[vp]:https://github.com/vuphan314
[tikzuml]:http://perso.ensta-paristech.fr/~kielbasi/tikzuml/
