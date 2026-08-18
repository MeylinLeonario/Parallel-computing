<table>
    <tr>
        <td>
        <img src ="tile018.png">
        </td>
        <td width="70%" valign="middle">
            En esta oportunidad, vamos a estudiar la diferencia entre un programa secuencial y un programa con concurrencia.
        </td>
    </tr>
</table>

## LÓGICA
La concurrencia debería de hacer las acciones mucho más rápidas, esto debido a que se ejecutan al mismo tiempo, contrario a una técnica secuencial.
Así, vemos en nuestra tarea que ejecutar las tareas A y B secuencialmente toma casi el doble que ejecutarlas concurrentemente.

### Obsevaciones
- Se utilizó la librería `<thread>` para realizar los hilos.
De estos hilos, se utilizaron los comandos `thread` + nombre del thread para distinguirlos.
Ejemplo: `thread t1()`, `thread t2()`

- Se utilizó además la librería chrono para poder realizar empezar el reloj, terminarlo y calcular la duración entre los tiempos con los comandos `high_resolution_clock::now()` y `duration_cast<microseconds>(stop-start)`
