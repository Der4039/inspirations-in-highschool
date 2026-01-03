# inspirations-in-highschool
to note down daily thoughts and codings
## 2026.1.3 Modeling equivalent resistance by using graph theory - 2026.1.3
In a complex circuit(especially 3D circuits), caculating equivalent resistance by enumerating each branches is difficult. I notice that almose any circuits can be seen as a DAG. Therefore, I can use topology and recursion to imitate how it works. As far as I am concerned, compared with the method of using kirhhoff's law and solving systems of equations, which may involve Gauss elimination, this method recessively uses kirhhoff's law, and just provides an order way(by recursion) to solve systems of equations.
