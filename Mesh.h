/* Mesh.h file description:
* Defines the Mesh class, and states all of the functions that it will have as defined in "Mesh.cpp".
*
* A Mesh stores information about and generates meshes.
*/

#pragma once

#include <vector>
#include <glad/glad.h>

class Mesh{
    private:
        GLenum GLusage = GL_STATIC_DRAW;
    public:
        // Vectors to store all vertices and indices.
        std::vector<GLfloat> vertices;
        std::vector<GLuint> indices;

        // The IDs of the VAO, VBO, and EBO.
        GLuint VAOID;
        GLuint VBOID;
        GLuint EBOID;

        Mesh(){
            // Generate and bind the VAO.
            glGenVertexArrays(1, &VAOID);
            glBindVertexArray(VAOID);

            // Generate the VBO and EBO.
            glGenBuffers(1, &VBOID);
            glGenBuffers(1, &EBOID);

            // Populate the VBO and EBO with blank data. (Cause the vertices and indices aren't set yet.)
            regenerateVBOAndEBO();

            // Rebind the VAO, VBO, and EBO. (The regenerateVBOsAndEBOs function unbound them.)
            glBindVertexArray(VAOID);
            glBindBuffer(GL_ARRAY_BUFFER, VBOID);
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBOID);

            // Set the VAO information.
            // First 3 floats are position.
            glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
            glEnableVertexAttribArray(0);

            // Second 3 floats are color.
            glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
            glEnableVertexAttribArray(1);

            // Third 2 floats are texture coordinates.
            glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
            glEnableVertexAttribArray(2);

            // Unbind VAO, VBO, and EBO.
            glBindVertexArray(0);
            glBindBuffer(GL_ARRAY_BUFFER, 0);
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
        }

        // Regenerate the VBO and EBO with the vertices and indices vectors.
        void regenerateVBOAndEBO();

        // Draw the mesh.
        void draw();

        // Delete the VAO, VBO, and EBO.
        void cleanup();
};
