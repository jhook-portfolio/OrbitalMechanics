#include <iostream>
#include <vector> 
#include "../src/two_body_model.h"
#include "../dependencies/crow/crow.h"

int main() {
    crow::SimpleApp app;

    CROW_ROUTE(app, "/")([](){
        return "Hello world";
    });

    app.port(18080).multithreaded().run();

    return 0;
}