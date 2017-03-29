<h6>top</h6>

# Cry
cryptographic framework

## `git`
```
git clone https://github.com/vuphan314/cry
cd cry
git branch -a
```

## dependencies
[GMP][gmp]

### GMP on Mac OS
with a terminal using [Homebrew][homebrew]:
```
brew install gmp
```

## contributors
- [Daniel Dunning][dd]
- [Michael DeGraw][md]
- [Vu Phan][vp]

## status
under development

## links
- [find files][find]
- [releases/deliverables][releases]
- [C++ source][src]

## convention
preferred max line length: 60-character

## TeX compilation
- with Atom: https://atom.io/packages/latex
- with a terminal:
  ```
  cd project3/report/

  latexmk -pdf -synctex=1 report.tex
  ```

## C++ compilation
with a terminal:
```
cd src/
./main.sh
```

## acknowledgement
[TikZ-UML][tikzuml]: TeX package for UML diagrams

<!--------------------------------------------------------->

[dd]:https://github.com/dannydthesloth
[md]:https://github.com/electr0sheep
[vp]:https://github.com/vuphan314

[find]:https://github.com/vuphan314/cry/find/master
[releases]:https://github.com/vuphan314/cry/releases
[src]:https://github.com/vuphan314/cry/tree/master/src

[tikzuml]:http://perso.ensta-paristech.fr/~kielbasi/tikzuml/

[gmp]:https://gmplib.org/
[homebrew]:https://brew.sh/
