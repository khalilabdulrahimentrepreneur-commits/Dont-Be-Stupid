#include <iostream>
#include <string>
#include <unordered_map>
#include <json/json.h> // Ensure you have a JSON library included (like jsoncpp)

using namespace std;

// Simulated FastAPI Endpoint structure
struct FastApiEndpoint {
    string path;
    string method; // e.g., GET, POST
    unordered_map<string, string> parameters; // Query parameters
};

// Function to convert FastAPI endpoint to a transferable payload
Json::Value convertToTransferablePayload(const FastApiEndpoint &endpoint) {
    Json::Value payload;
    payload["path"] = endpoint.path;
    payload["method"] = endpoint.method;

    // Add parameters to the payload
    for (const auto &param : endpoint.parameters) {
        payload["parameters"][param.first] = param.second;
    }

    return payload;
}

// Example usage of the conversion tool
int main() {
    FastApiEndpoint endpoint;
    endpoint.path = "/api/v1/resource";
    endpoint.method = "POST";
    endpoint.parameters = {
        {"name", "string"},
        {"value", "int"}
    };

    // Convert endpoint to Transferable Payload
    Json::Value payload = convertToTransferablePayload(endpoint);

    // Output the JSON format of the payload
    Json::StreamWriterBuilder writer;
    string jsonString = Json::writeString(writer, payload);
    cout << "Transferable Payload:" << endl;
    cout << jsonString << endl;

    return 0;
}
