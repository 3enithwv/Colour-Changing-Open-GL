#define _USE_MATH_DEFINES
#include <GLFW/glfw3.h>
#include <iostream>
#include <cmath>

class rgbwaves {
public:
double pi_val = M_PI; 
    // Method 1: Add two numbers
    double Linear(double x, double h, double d, double a) {
        double y = (h / 2.0 * (( (2.0 * d * (x + a - 1.0 / d) - 2.0) - 2.0 * std::floor((2.0 * d * (x + a - 1.0 / d) - 2.0) / 2.0) ) * (2.0 * std::floor( (d * (x + a - 1.0 / d)) - 2.0 * std::floor((d * (x + a - 1.0 / d)) / 2.0) ) - 1.0) + std::floor( (d * (x + a + 1.0 / d) + 1.0) - 2.0 * std::floor((d * (x + a + 1.0 / d) + 1.0) / 2.0) ) * 2.0) - h / 2.0) * std::abs(std::floor(((d * (x + a)) - 3.0 * std::floor((d * (x + a)) / 3.0)) / 3.0 - 1.0 / 3.0)) + h / 2.0 * (std::abs(std::floor(((d * (x + a)) - 3.0 * std::floor((d * (x + a)) / 3.0)) / 3.0 - 1.0 / 3.0)) + 2.0 * std::abs(std::abs(std::floor(2.0 * std::floor(((d * x + d * a) - 6.0 * std::floor((d * x + d * a) / 6.0))) / 5.0 - 0.2)) - 1.0));

        return y;
    }

    // Method 2: Subtract two numbers
    double Sine(double x, double h, double d, double a) {
        double y = (h/2.0)*std::sin(d*(x+a-1.0/(2.0*d))*M_PI)*std::abs(std::floor(std::fmod(d*(x+a),3.0)/3.0-1.0/3.0))+(h/2.0)*(std::abs(std::floor(std::fmod(d*(x+a),3.0)/3.0-1.0/3.0))+2.0*std::abs(std::abs(std::floor(2.0*std::floor(std::fmod(d*x+d*a,6.0))/5.0-0.2))-1.0));

        return y;

    }

    // Method 3: Multiply two numbers
    double Quadralic_Upwards(double x, double h, double d,double a) {
        double y = h * (std::pow(std::fmod(d * (x + a) - 1.0, 2.0) - 1.0, 4.0) - 0.5) * std::abs(std::floor(std::fmod(d * (x + a), 3.0) / 3.0 - 1.0 / 3.0)) + (h / 2.0) * (std::abs(std::floor(std::fmod(d * (x + a), 3.0) / 3.0 - 1.0 / 3.0)) + 2.0 * std::abs(std::abs(std::floor(2.0 * std::floor(std::fmod(d * x + d * a, 6.0)) / 5.0 - 0.2)) - 1.0));
        return y;

    }

    // Method 4: Divide two numbers
    double Quadralic_Downwards(double x, double h, double d,  double a){
        double y = h * (-std::pow(std::fmod(d * (x + a), 2.0) - 1.0, 4.0) + 0.5) * std::abs(std::floor(std::fmod(d * (x + a), 3.0) / 3.0 - 1.0 / 3.0)) + (h / 2.0) * (std::abs(std::floor(std::fmod(d * (x + a), 3.0) / 3.0 - 1.0 / 3.0)) + 2.0 * std::abs(std::abs(std::floor(2.0 * std::floor(std::fmod(d * x + d * a, 6.0)) / 5.0 - 0.2)) - 1.0));

        return y;
    } 

};


int main(){

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    int width = 800;
    int height = 800;

    GLFWwindow* window = glfwCreateWindow(width, height, "KoboshJoei - Colour Madness", NULL, NULL);

    if (window == NULL){
        std::cout << "WINDOW FAILED LOL" << std::endl;
        glfwTerminate();
        return -1;
    }
    

    glfwMakeContextCurrent(window);

    rgbwaves Waves;
    
    int change = 100000;

    // rgb VALUES
    
    int r = 0;
    int b = 2;
    int g = 4;

    
    int l = 1000;
    double h = 1;
    int d = 1;

    double red = 0;
    double blu = 0;
    double grn = 0;    

    double x = 0;

    float alpha = 0.5;

    glViewport(0, 0, height, width/2);

    glClearColor(red/100, grn/100, blu/100, alpha);
    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(window);
    int kobosh = 1;
    while(!glfwWindowShouldClose(window)){

        glfwPollEvents();

        x += 0.002;

        red = Waves.Linear(x, h, d, r);
        grn = Waves.Linear(x, h, d, g);
        blu = Waves.Linear(x, h, d, b);
        glBegin(GL_QUADS);         // Start drawing a Quadrilateral
   

        glViewport(0, 0, height, width/2);
        glClearColor((red*100)/100, (grn*100)/100, (blu*100)/100, alpha);
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);

        std::cout << "(" << int(red*225) << ", " <<  int(grn*225) << ", " << int(blu*225) << ", " << alpha << ")" << std::endl;
    }

    // It kills itself
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
    
}