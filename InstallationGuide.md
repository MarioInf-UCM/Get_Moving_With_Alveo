# GET MOVING WITH ALVEO 


<br />

## Paso 1 - Instalar el paquete de la tarjeta Alveo u200

Recomendamos seguir los pasos indicados a continuación, pero en el caso de quererse llevar a cabo el proceso de instalación predeterminado, [ver aquí](./markdown/defaultInstallationPackage.md).

El proceso de instalación puede variar dependiendo del Sistema Operativo que queramos utilizar. En nuestro caso vamos a emplear las herramientas de la versión *2023.2* y se llevará a cabo la instalación en un sistema *Debian 12*, para la cual deberemos seleccionar la versión correspondiente de *Ubuntu*, siendo esta la *22.04*.


```BASH
#1. Importación de la clave pública
wget -qO - https://www.xilinx.com/support/download/2020-2/xilinx-master-signing-key.asc | sudo tee /etc/apt/trusted.gpg.d/myrepo.asc


#2. Agregamos el servidor de descargas a la lista de fuentes para apt
#En el caso de encontrarnos en Ubuntu 22.04:
echo "deb https://packages.xilinx.com/artifactory/debian-packages $(lsb_release -cs) main" | sudo tee -a /etc/apt/sources.list.d/xlnx.list
#En el caso de encontrarnos en Debian 12:
echo "deb https://packages.xilinx.com/artifactory/debian-packages jammy main" | sudo tee -a /etc/apt/sources.list.d/xlnx.list


# 3. Instalación de bibliotecas previas:
cd ~/Descargas
wget http://archive.ubuntu.com/ubuntu/pool/main/p/protobuf/libprotobuf23_3.12.4-1ubuntu7.22.04.1_amd64.deb
dpkg -i libprotobuf23_3.12.4-1ubuntu7.22.04.1_amd64.deb


#4. Instalación de la biblioteca
sudo apt update && sudo apt install -y xilinx-u200*
```

El resultado obtenido tras la instalación debe ser similar al siguiente:

```BASH
.
.
.
Loading new XRT Linux kernel modules
Installing MSD / MPD daemons
| Components                   |      Status        |
|------------------------------|--------------------|
| XOCL & XCLMGMT Kernel Driver | Success            |
| XRT USERSPACE                | Success            |
| MPD/MSD                      | Success            |
Setting up xilinx-cmc-u200-u250 (1.2.23-3395909) ...
Setting up xilinx-sc-fw-u200-u250 (4.6.21-1.fd1b20d) ...
Setting up xilinx-u200-gen3x16-xdma-validate (2-3514848) ...
Setting up xilinx-u200-gen3x16-xdma-base (2-3498633) ...
Partition package installed successfully.
Flash the card by following the instructions in the card's installation guide.
```


<br />

## Paso 2 - Proceso de instalación del hardware

Para llevar a cabo el proceso de instalación del hardware de la tarjeta *Alveo u200* deberemos seguir la guía [Getting Started with Alveo Data Center Accelerator Cards User Guide (UG1301)](https://docs.amd.com/r/en-US/ug1301-getting-started-guide-alveo-accelerator-cards/Introduction). Esto debe llevarse a cabo en el equipo donde se encuentre instalada la tarjeta, ya sea un servidor o el mismo dispositivo de trabajo, sin embargo, no debe ser reproducido en aquellos que no dispongan del hardware y vayan a llevar a cabo despliegue de forma remota.

Siguiendo dicha guía serán instalados tanto el *Runtime (XRT)* para la comunicación con la placa como el *Deployment Target Platform* para llevar a cabo el despliegue de aplicaciones en la misma.



<br />

## Paso 3 - Instalación de la plataforma de la tarjeta Alveo u200

Para llevar a cabo la instalación de la plataforma deberemos llevar a cabo la descarga de la misma desde el siguiente [enlace](https://account.amd.com/en/forms/downloads/eula-xef.html?filename=xilinx-u200-gen3x16-xdma-2-202110-1-dev_1-3514848_all.deb). En el caso de que este no funciones, podemos acceder al mismo mediante dentro del apartado [Getting started - Vitis Desing Flow](https://www.xilinx.com/products/boards-and-kits/alveo/u200.html#vitis).

Una vez descargado ejecutamos los siguientes comando (en el caso de que hayan actualizado de versión, el nombre del ejecutable puede variar):

```BASH
cd ~/Descargas
dpkg -i xilinx-u200-gen3x16-xdma-2-202110-1-dev_1-3514848_all.deb
```



<br />

## Paso 4 - Instalación de la herramientas de desarrollo

Para poder desarrollar para la plataforma Alveo u200 necesitaremos tener instaladas las herramientas proporcionadas por *Xilinx*, las cuales son:
- **Vitis:** Para un desarrollo de alto nivel basado en c++ con una posterior traducción automática a lenguaje de definición de circuitos.
- **Vivado:** Pensado para llevar a cabo un desarrollo directo mediante lenguaje de definición de circuitos.

la instalación de la herramienta *Vitis* trae consigo la instalación automática de *Vivado* aunque no viceversa. Pese a esto, recomendamos instalar ambas herramientas mediante la *Unified Software Platform* que podemos descargar en el siguiente [enlace](https://www.xilinx.com/support/download/index.html/content/xilinx/en/downloadNav/vitis.html).

Tener en cuenta descargar la versión apropiada y llevar a cabo las actualizaciones posteriores que pueden encontrarse también en el mismo enlace.

> [!IMPORTANT]
> 
> En el caso de instalar Vivado, para el correcto reconocimiento de la plataforma Alveo u200 deberemos incluir en el mismo el archivo de especificación XDC. Para hacer esto deberemos descargarlo desde el siguiente [enlace](https://www.xilinx.com/bin/public/openDownload?filename=alveo-u200-xdc_20210909.zip) o en el caso de que no funcione, podemos acceder al mismo mediante dentro del apartado [Getting started - Vitis Desing Flow](https://www.xilinx.com/products/boards-and-kits/alveo/u200.html#vitis).
> 
> Una vez hecho esto deberemos incluir el fichero dentro de la estructura de Vitis. Para las versiones igual y posteriores a la 2021.1, deberemos pegarlo en el siguiente directorio: `<path_xilinx>/xilinx/Vivado/<version>/data/xhub/boards/XilinxBoardStore/boards/Xilinx/`


<br />

## Paso 5 - Preparación del tutorial

El presente tutorial esta basado en tutorial oficial [get moving with Alveo](https://github.com/Xilinx/Get_Moving_With_Alveo), pero este ha sido adaptado para facilitar su entendimiento y claridad. Se recomienda realizar los siguientes pasos en base al mismo y no a la versión oficial.


#### 1. Instalación OpenCV 

Para poder llevar a cabo la correcta ejecución del tutorial [get moving with Alveo](https://github.com/Xilinx/Get_Moving_With_Alveo) debemos realizar la instalación de la biblioteca de análisis visual OpenCV. Aunque en la documentación oficial se ejemplifica estos pasos mediante la versión `4.4.0`, recomendamos descargar la *release* de la versión más reciente o la que prefiera el usuario (esto quiere decir que los siguientes pasos deben llevarse a cabo, no dentro del repositorio oficial, sino dentro de la versión correspondiente a la release descargada).

```BASH

#Descarga de los repositorios
mkdir /opt/opencv/
mkdir /opt/opencv/sources

sudo git clone https://github.com/opencv/opencv.git /opt/opencv/sources
sudo git clone https://github.com/opencv/opencv_contrib.git /opt/opencv/sources
sudo git clone https://github.com/opencv/opencv_extra.git /opt/opencv/sources
 
#Configuracion del CMake
mkdir /opt/opencv/sources/opencv/build
cd /opt/opencv/sources/opencv/build

cmake  .. -D CMAKE_BUILD_TYPE=Release -D CMAKE_INSTALL_PREFIX=/opt/opencv/<version> -D OPENCV_EXTRA_MODULES_PATH=/opt/opencv/sources/opencv_contrib/modules/ -D OPENCV_TEST_DATA_PATH=/opt/opencv/sources/opencv_extra/testdata -D BUILD_DOCS=yes -D BUILD_EXAMPLES=yes

#Compilacion
make -j<numProc>

#Instalación
sudo make install

#Ejecución del test Core (opcional)
./opt/opencv/sources/opencv/build/bin/opencv_test_core

```

#### 2. Configuración de variables de entorno

Posteriormente deberemos configurar las variables de necesarias tanto para que los ejemplos puedan utilizar las herramientas de *Vitis* y *Vivado* *openCV*. El valor de estas dependerán de donde se ha situado la instalación de dichas herramientas:

```BASH
# XILINX'S TOOLS CONFIGURATION
########################################
source <path_xilinx>/xilinx/Vivado/<version>/settings64.sh
source <path_xilinx>/xilinx/Vitis/<version>/settings64.sh
source <path_xilinx>/xilinx/xrt/setup.sh > /dev/null


# GET MOVING WITH ALVEO
########################################
#export PLATFORM=xilinx_u200_gen3x16_xdma_2_202110_1
#export PLATFORM_REPO_PATH=<path_xilinx>/xilinx/platforms/

export OPENCV_INCLUDE=<path_opencv>/opencv/<version>/include/
export OPENCV_LIB=<path_opencv>/opencv/<version>/lib/
export LD_LIBRARY_PATH=<path_opencv>/opencv/<version>/lib:$LD_LIBRARY_PATH
```


#### 3. Compilación del diseño hardware

Los ficheros que conforman el diseño hardware se encuentran dentro de la carpeta `hw_src`, donde podemos encontrar tanto los ficheros `*.cpp` de los kernels que vamos a descargar en la plataforma *Alveo Uu200* como los diferentes ficheros de compilación y el `Makefile` correspondiente. 

Previamente a realizar la compilación necesitaremos descargar el repositorio [Vitis_Libraries](https://github.com/Xilinx/Vitis_Libraries) dentro del directorio `hw_src`.

```BASH
cd <path_getMovingWithAlveo>/hw_src
git clone git@github.com:Xilinx/Vitis_Libraries.git
```

Posteriormente, deberemos especificar dentro del fichero `config.mk` la plataforma para la cual vamos compilar los kernels. En nuestro caso, la configuración sera la siguiente:

```Makefile
TARGET ?= sw_emu    # Options for TARGET: sw_emu, hw_emu and hw
DEVICE ?= u200      # Options for DEVICE: u200, u250. Default platform is XDMA, defined by PLATFORM
PLATFORM ?= xilinx_$(DEVICE)_gen3x16_xdma_2_202110_1
PLATFORM_REPO_PATH ?= /opt/xilinx/platforms/
```

Finalmente, realizamos la compilación de los kernels mediante el uso del fichero `Makefile`:
```BASH
cd <path_getMovingWithAlveo>/hw_src
make
```

> [!IMPORTANT]
>
> Es posible que durante los pasos finales de la compilación, mientras se realiza el proceso de enlazado de los kernels, el compilador de detecte los siguientes errores:
>



```BASH
ERROR: [v++ 17-1309] Gcc: /usr/include/features-time64.h:20:10: fatal error: bits/wordsize.h: No such file or directory

#Instalación de los paquetes correspondientes.
sudo apt install glibc-*

#Mover los paquetes al directorio correcto
sudo cp -r /usr/include/x86_64-linux-gnu/bits/* /usr/include/bits/
```


```BASH
ERROR: [v++ 17-1309] Gcc: /usr/include/features.h:489:12: fatal error: sys/cdefs.h: No such file or directory

#Instalación de los paquetes correspondientes.
sudo apt install libc6-dev-i386
```