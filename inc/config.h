/**
 * @brief Seleccion del tipo de memoria a utilizar
 * 
 * 0: Memoria estatica, 1: Memoria dinamica
 */
#define TIPO_MEMORIA 1

// Definición de macros según el tipo de memoria
#if TIPO_MEMORIA == 0
    #define USAR_MEMORIA_ESTATICA
#elif TIPO_MEMORIA == 1
    #define USAR_MEMORIA_DINAMICA
#else
    #error "Error: TIPO_MEMORIA no definido correctamente. Debe ser 0 (memoria estatica) o 1 (memoria dinamica)."
#endif

// Configuración especifica para memoria estatica
#ifdef USAR_MEMORIA_ESTATICA
    #define ALUMNO_MAX_INSTANCIAS 1 //!< Cantidad maxima de instancias
#endif