# Computación Gráfica
## Gilberto Espinoza
### Universidad de Santiago de Chile

En este repositorio manejare lo que es el curso electivo de Computación Gráfica impartido en USACH en la ciudad de Santiago Chile.

## Secciones
1. Primitivas Graficas

## Instalacion.
Este proyecto utiliza la libreria `graphics.h` que no se encuentra en el estándar de C++. Asi que la agregaremos a nuestro compilador y haremos un link dentro de Code::Blocks para que nuestro proyecto pueda ser compilado.
### Incluye los archivos
Copia los archivos `graphics_h/graphics.h` y `winbgim.h` en ` C:\Program Files (x86)\CodeBlocks\MinGW\include` o en la instalacion correspondiente de tu Code::Blocks.

Copia el archivo `libbgi.a` en ` C:\Program Files (x86)\CodeBlocks\MinGW\lib`

### Agrega Link Libraries en Linker Settings
1. En Code::Blocks ve a, Settings > Compiler.
2. Click en Linker Settings.
3. En Link Libraries, agrega y dirigete a `C:\ProgramFiles(x86)\CodeBlocks\MinGW\lib\` and select `libbgi.a`.
4. Copia esto en la parte de Other Linker Option en Linker Settings (i.e. en el lado derecho)

`-lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32`

5. Guarda y reinicia la aplicacion.
