#pragma once

#include "Entidad.hpp"
#include "vector"

// GLM library
#include "vec3.hpp" // glm::vec3
#include "vec4.hpp" // glm::vec4
#include "mat4x4.hpp" // glm::mat4
#include <ext/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale

class Nodo
{
public:
    Nodo (Entidad *ent, Nodo *p); 
    ~Nodo ();

    void añadirHijo (Nodo *h);
    void borrarHijo (Nodo *h);

    void setMatrizTransf (glm::mat4x4 mat);
    glm::mat4x4 getMatrizTransf ();

    void setEntidad (Entidad *ent);
    Entidad *getEntidad ();

    std::vector<Nodo*> getHijos ();

    void setPadre (Nodo *p);
    Nodo *getPadre ();

    void setTraslacion (glm::vec3 tras);
    glm::vec3 getTraslacion ();

    void setRotacion (glm::vec3 rot);
    glm::vec3 getRotacion ();

    void setEscalado (glm::vec3 esc);
    glm::vec3 getEscalado ();

    void trasladar (glm::vec3 tras);
    void rotar (glm::vec3 rot);
    void escalar (glm::vec3 esc);

    void recorrer (glm::mat4x4 matAcum, unsigned int shader); 

    void setActualizarMatriz (bool act);

private:
    glm::mat4x4 matrizTransf;
    Entidad *entidad;
    std::vector <Nodo*> hijos;
    Nodo *padre;
    glm::vec3 traslacion;
    glm::vec3 rotacion;
    glm::vec3 escalado;
    bool actualizarMatriz;
};