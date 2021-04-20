#include <iostream>
#include <chrono>
#include <cpr/cpr.h>
#include <string>

int main() {
    std::cout << "InfluxDB REST API Communication Application\n";

    //get current Unix Timestamp
    long long t = std::chrono::time_point_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now()).time_since_epoch().count();
    std::cout << "UNIX Timestamp in ns: " << t << '\n';
    float pseudo_measurement = 49.77;
    std::string lineprotocol = "testmeasurement,pseudotag=pseudo1 test_percent=";
    lineprotocol += std::to_string(pseudo_measurement);
    lineprotocol += " ";
    lineprotocol += std::to_string(t);
    std::cout << lineprotocol << '\n';



 
    cpr::Response r = cpr::Post(cpr::Url{"http://localhost:8086/api/v2/write?org=roboflex&bucket=roboflex&precision=ns"},
                   cpr::Body{lineprotocol},
                   cpr::Header{{"Authorization", "Token ZfDXfC6AJrnGh012kehanBF6h-w5zzcjj7rXMPjxiO3UhWQGPUHFtxTQGo0RNK-3Uw5PcJe_lsRc7FZOvXax3w=="}});

    std::cout << r.text << std::endl;


    return EXIT_SUCCESS;
}

//curl example to send measurements
/*
curl --request POST "http://localhost:8086/api/v2/write?org=YOUR_ORG&bucket=YOUR_BUCKET&precision=s" \
  --header "Authorization: Token YOURAUTHTOKEN" \
  --data-raw "
mem,host=host1 used_percent=23.43234543 1556896326
mem,host=host2 used_percent=26.81522361 1556896326
mem,host=host1 used_percent=22.52984738 1556896336
mem,host=host2 used_percent=27.18294630 1556896336
"
*/