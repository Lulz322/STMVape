#include <bluetooth/bluetooth.h>
#include <bluetooth/hci.h>
#include <bluetooth/hci_lib.h>

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <cerrno>
#include <array>
#include <iomanip>
#include <vector>
#include <boost/optional.hpp>

#include <signal.h>

#include <stdexcept>

#include <blepp/logging.h>
#include <blepp/pretty_printers.h>
#include <blepp/blestatemachine.h> //for UUID. FIXME mofo
#include <blepp/lescan.h>

using namespace std;
using namespace BLEPP;

void catch_function(int)
{
	cerr << "\nInterrupted!\n";
}



int main(int argc, char** argv)
{
	gatt.connect_blocking("d6:41:a7:3b:f6:be");
	char* data = "!!#RTH\x0c";
	while(done == false) {
	gatt.read_and_process_next();
	}
	gatt.send_write_request(0x12, (const uint8_t*)data, strlen(data));
	gatt.write_and_process_next();
	while(true) {
	gatt.read_and_process_next();
	}

}