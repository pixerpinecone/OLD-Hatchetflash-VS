//=-= =-= =-= =-= =-= =-= =-= =-=       =-= =-= =-= =-= =-= =-= =-=       =-= =-= =-= =-= =-= =-= =-= 
/*   TextureAtlas.h file description:
* A texture atlas is a large texture composed of a bunch of smaller textures, such as a grid of block textures in this case.
* Many of the functions are defined in "BlockTextureAtlas.cpp".
*////=-= =-= =-= =-= =-= =-= =-= =-=       =-= =-= =-= =-= =-= =-= =-=       =-= =-= =-= =-= =-= =-= =-= 

#pragma once

#include <vector>
#include <map>
#include <fstream>
#include <sstream>
#include <filesystem>

#include<glad/glad.h>
#include<stb/stb_image.h>

#include"shaderClass.h"


// Declares a class which can store a bunch of textures as one big indexable texture, known as the/a "texture atlas".
class BlockTextureAtlas
{
	public:
		// A list of public variables that a block-texture-atlas object stores.
		unsigned int numberOfImagesInTextureAtlas = 0; //(Helps us keep track of how many unique images/textures are actually IN the texture atlas.)
		GLuint ID = 0; //(0 is the equivalent of unbound, it's only assigned here since VS likes it initialized. It's used for complicated OpenGL stuff, specifically binding-related. Research/rename it later.)
		GLenum textureImageType = GL_TEXTURE_2D; //It will almost certainly always be this, so even if it is assigned in the object construction, it's nice to put this here.
		std::map<std::string, float> imageNameToTexcoordsMap;

		// The main constructor for the texture atlas object and all of it's variables, it's defined in "BlockTextureAtlas.cpp".
		BlockTextureAtlas(const char* inputFolderDirectory, GLenum inputTextureImageType, GLenum inputGLTextureUnitSlot, GLenum inputImageInformationFormat, GLenum inputDataTypeOfPixelData);
	
		void texUnit(Shader& shader, const char* uniform, GLuint unit); //(States a function which assigns a texture unit to a texture.)
		
		// Custom functions which relate to fetching textures and related from material and related STID numbers.
		void getTextureCoordinatesFromTwoStidNumbers();
		void getRGBColorEffectNumbersFromTwoStidNumbers();

		// States some basic functions as defined in "Texture.cpp".
		void Bind();
		void Unbind();
		void Delete();
};

class CantLoadImageException{}; //(Currently used for error related stuff.)
class CantLoadMapFileException{}; //(Currently used for error related stuff.)

//=-= =-= =-= =-= =-= =-= =-= =-=       =-= =-= =-= =-= =-= =-= =-=       =-= =-= =-= =-= =-= =-= =-= 