<h6>top</h6>

# Cry
cryptographic framework

## links
- [find pdf][find]
- [releases][releases]
- projects
  - 1 (project plan)
    - [presentation][presentation1]
    - [report][report1]
  - 2 (software requirements specification)
    - [presentation][presentation2]
    - [report][report2]
    - [interview][interview2]
- [C++ source][src]

## convention
preferred max line length: 60-character

## contribution
```
git clone https://github.com/vuphan314/cry
cd cry/
git branch -a
git checkout <your_branch>
```
- make change, commit, push
- create a pull request on GitHub
  from `<your_branch>` to `master`

## TeX compilation
- with Atom: https://atom.io/packages/latex
- with a terminal:
  ```
  cd project3/report/

  latexmk -pdf -synctex=1 interview.tex
  ```

## Acknowledgement
[TikZ-UML][tikzuml]: TeX package for UML diagrams

<!--------------------------------------------------------->

[find]:https://github.com/vuphan314/cry/find/master
[releases]:https://github.com/vuphan314/cry/releases

[presentation1]:https://github.com/vuphan314/cry/blob/master/project1/presentation/presentation.pdf
[report1]:https://github.com/vuphan314/cry/blob/master/project1/report/report.pdf

[presentation2]:https://github.com/vuphan314/cry/blob/master/project2/presentation/presentation.pdf
[report2]:https://github.com/vuphan314/cry/blob/master/project2/report/report.pdf
[interview2]:https://github.com/vuphan314/cry/blob/master/project2/interview/interview.pdf

[src]:https://github.com/vuphan314/cry/tree/master/src

[tikzuml]:http://perso.ensta-paristech.fr/~kielbasi/tikzuml/
