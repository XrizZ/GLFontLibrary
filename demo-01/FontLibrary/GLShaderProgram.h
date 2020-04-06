#pragma once
#include "..\glew\include\GL\glew.h"

class CGLShaderProgram
{
public:
	CGLShaderProgram();
	CGLShaderProgram(const CGLShaderProgram& glShaderProgram);
	~CGLShaderProgram();

	// FUNCTIONS TO CREATE THE SHADER PROGRAM
	bool		InitFromFile(const std::string& aVertexShaderFileName, const std::string& aFragmentShaderFileName);
	bool		InitFromString(const std::string& vertexShaderSourceCode, const std::string& fragmentShaderSourceCode);
	GLuint		GetProgramID(){return m_shaderProgram;};

protected:
	// PROTECTED VARIABLES
	std::string		m_vertexSource;
	std::string		m_fragmentSource;

	GLuint			m_vertexShader;
	GLuint			m_fragmentShader;

	GLuint			m_shaderProgram;

private:

	// For cleanup
	void CleanUp();

	// HELPER FUNTIONS FOR CREATING SHADER PROGRAM
	GLuint		CompileShader(GLenum aShaderType, const char* aShaderSource);
	bool		CheckForErrors(CString aFile = __FILE__, int aLine = __LINE__);
	CString		LoadCompleteFile(CString aFileName);
};