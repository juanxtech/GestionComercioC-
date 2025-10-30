# 💻 Gestión de Comercio de Informática (Proyecto C++)

Este proyecto es una aplicación de consola desarrollada en **C++** para la **gestión completa de una tienda de informática**.  
Fue creado como **proyecto final** para la asignatura **Programación II (Segundo Cuatrimestre)** de la universidad.

El objetivo principal fue **aplicar conceptos avanzados de programación estructurada**, manejo de memoria (punteros y referencias), **modularización** y **persistencia de datos** mediante manejo de **archivos binarios**.

---

## 🌟 Características Principales

El sistema implementa la funcionalidad **ABML (Alta, Baja, Modificación, Listado)** para las principales entidades del negocio, asegurando la **integridad referencial** entre ellas.

---

## 🧩 Entidades y Módulos

| **Módulo** | **Funcionalidades Clave** |
|-------------|-----------------------------|
| **Clientes** | - ABML completo.<br>- Listado de clientes activos e inactivos.<br>- Reporte del cliente con mayor recaudación histórica. |
| **Vendedores** | - ABML básico de personal de ventas. |
| **Equipos (Productos)** | - ABML.<br>- Consulta de stock disponible.<br>- Consulta por tipo de equipo.<br>- Reporte de equipos más vendidos. |
| **Ventas** | - Registro completo de ventas.<br>- Requiere ID de Cliente y Vendedor válidos.<br>- Descuento automático del stock del equipo vendido.<br>- Filtrado y listado de todas las ventas. |

---

## 🛠️ Tecnologías Utilizadas

- **Lenguaje:** C++ (Estándar C++11/C++14)  
- **Paradigma:** Programación Estructurada y Modular  
- **Persistencia:** Archivos binarios para almacenamiento de datos (Clientes, Vendedores, Equipos, Ventas)  
- **Herramientas de Desarrollo:** Visual Studio / MinGW  

---

## 📂 Estructura del Proyecto

El proyecto está modularizado para **separar la lógica de negocio** (archivos `.cpp`) de las **interfaces de definición** (archivos `.h`).

| **Directorio** | **Contenido** |
|-----------------|----------------|
| `src/` | Archivos de implementación (`.cpp`). Contiene la lógica de las clases y las funciones principales de los menús. |
| `include/` | Archivos de encabezado (`.h`). Contiene las definiciones de las clases (`Persona`, `Cliente`, `Vendedor`, `Equipo`, `Venta`) y las interfaces de las funciones. |
| `Project1/` | Archivos de solución de Visual Studio (`.sln`, `.vcxproj`). |
| `data/` | *(Recomendado)* Carpeta para almacenar los archivos binarios de la aplicación (`clientes.dat`, `ventas.dat`, etc.). |
| `.gitignore` | Reglas para ignorar archivos generados por el compilador (como `.exe`, `.obj`, `.ipch`, `.vs`). |

---

## 🚀 Cómo Compilar y Ejecutar

### 🧰 Requisitos
- Un compilador de C++ (ej. **GCC**, **Clang** o el **compilador de Visual Studio**)  
- Un IDE compatible (**Visual Studio 2019** o posterior recomendado)

### 🔧 Instrucciones

#### 1️⃣ Clonar el repositorio:
```bash
git clone https://github.com/juanxtech/GestionComercioC-.git
cd GestionComercioC-
```
#### 2️⃣ Abrir en Visual Studio:
- Abrir el archivo de solución Project1/Project1.sln

- Asegurarse de que el compilador esté configurado en modo Debug o Release

- Presionar F5 o seleccionar Depurar > Iniciar sin depurar para ejecutar

#### 3️⃣ Compilar con MinGW/GCC (desde consola):
```bash
g++ src/*.cpp -o gestion_comercio
./gestion_comercio
```

### 📚 Menús Detallados (Funcionalidad ABML)
#### 👥 Menú Clientes
- Ingresar Cliente
- Baja Cliente (lógica de borrado suave/inactivación)
- Alta Cliente (reactivación)
- Modificar Cliente
- Listar Clientes (activos)
- Listar Clientes inactivos
- Buscar Cliente por ID
- Cliente que más recaudó

#### 🧑‍💼 Menú Vendedores
- Alta Vendedor
- Baja Vendedor
- Modificar Vendedor
- Listar Vendedores

#### 💻 Menú Equipos
- Alta Equipo
- Baja Equipo
- Modificar Equipo
- Listar Equipos
- Consultar por tipo de equipo
- Consultar equipos disponibles (Stock > 0)
- Informe equipos más vendidos

#### 💰 Menú Ventas
- Agregar Venta (proceso que actualiza el stock de equipos)
- Bajar Venta (anular)
- Modificar Venta
- Listar Ventas disponibles
- Filtrar Venta
- Listar todas las ventas
