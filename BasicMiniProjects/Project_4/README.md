# I/O vs CPU — Compara una tarea que espera archivos/red con otra que realiza cálculos intensivos y descubre por qué no todo paralelismo funciona igual.

La idea del proyecto es construir dos tareas:
- I/O-bound: pasa gran parte del tiempo esperando algo externo, por ejemplo, leer archivos, escribir archivos o esperar una respuesta de red.

- CPU-bound: pasa gran parte del tiempo haciendo cálculos, por ejemplo números primeros, matrices, hashing o cálculos matemáticos repetitivos.

Luego, hay que ejecutar cada una de forma secuencial y paralela, luego medir el tiempo y comparar.

### Observaciones
What the fuck.
Fue un experimento demasiado complicado. En esta oportunidad, decidí arriesgarme y separar todo por `.h` y por `.cpp`.

Lo que hice fue hacer una clase abstracta, `ITask.h`. Ésta no representa una tarea concreta, sino que representa las reglas que cualquier tipo de tarea debe cumplir:
 > Todas las tareas pueden ejecutarse.

 Sin `ITask` podríamos simplemente ejecutar con `void execute();` en todas las Tasks. Sin embargo, con `ITask` decimos que IOTask y CPUTask es un tipo de ITask.
`virtual void execute() = 0` permite que cada clase hija tengan su propia versión de `execute()`.

