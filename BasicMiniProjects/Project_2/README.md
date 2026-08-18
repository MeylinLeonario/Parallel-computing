# Cronómetro de rendimiento — Construye una pequeña herramienta con chrono para medir cuánto tarda una función y aprender a hacer benchmarks antes de intentar optimizar.

Para este caso se utilizó una función dentro de una función, la cual se pasó de la siguiente manera `int funcion1(void (*funcion2)())`.

### Consideraciones
- Se utilizó `volatile` para que el compilador no elimine la operación por pensar que el cálculo no afecta al programa, y así no medir un bucle vacío.