#include "AD936X_LIBIIO_base.h"

/*******************************************************************************************

    AUTO-GENERATED CODE. DO NOT MODIFY

    The following class functions are for the base class for the device class. To
    customize any of these functions, do not modify them here. Instead, overload them
    on the child class

******************************************************************************************/

AD936X_LIBIIO_base::AD936X_LIBIIO_base(char *devMgr_ior, char *id, char *lbl, char *sftwrPrfl) :
    frontend::FrontendTunerDevice<frontend_tuner_status_struct_struct>(devMgr_ior, id, lbl, sftwrPrfl),
    ThreadedComponent()
{
    construct();
}

AD936X_LIBIIO_base::AD936X_LIBIIO_base(char *devMgr_ior, char *id, char *lbl, char *sftwrPrfl, char *compDev) :
    frontend::FrontendTunerDevice<frontend_tuner_status_struct_struct>(devMgr_ior, id, lbl, sftwrPrfl, compDev),
    ThreadedComponent()
{
    construct();
}

AD936X_LIBIIO_base::AD936X_LIBIIO_base(char *devMgr_ior, char *id, char *lbl, char *sftwrPrfl, CF::Properties capacities) :
    frontend::FrontendTunerDevice<frontend_tuner_status_struct_struct>(devMgr_ior, id, lbl, sftwrPrfl, capacities),
    ThreadedComponent()
{
    construct();
}

AD936X_LIBIIO_base::AD936X_LIBIIO_base(char *devMgr_ior, char *id, char *lbl, char *sftwrPrfl, CF::Properties capacities, char *compDev) :
    frontend::FrontendTunerDevice<frontend_tuner_status_struct_struct>(devMgr_ior, id, lbl, sftwrPrfl, capacities, compDev),
    ThreadedComponent()
{
    construct();
}

AD936X_LIBIIO_base::~AD936X_LIBIIO_base()
{
    RX1A_0->_remove_ref();
    RX1A_0 = 0;
    RX1B_1->_remove_ref();
    RX1B_1 = 0;
    RX2A_2->_remove_ref();
    RX2A_2 = 0;
    RX2B_3->_remove_ref();
    RX2B_3 = 0;
    DigitalTuner_in->_remove_ref();
    DigitalTuner_in = 0;
    dataShortTX_in->_remove_ref();
    dataShortTX_in = 0;
    TX1A_0->_remove_ref();
    TX1A_0 = 0;
    TX1B_1->_remove_ref();
    TX1B_1 = 0;
    TX2A_2->_remove_ref();
    TX2A_2 = 0;
    TX2B_3->_remove_ref();
    TX2B_3 = 0;
    dataShortRX_out->_remove_ref();
    dataShortRX_out = 0;
}

void AD936X_LIBIIO_base::construct()
{
    loadProperties();

    RX1A_0 = new frontend::InRFInfoPort("RX1A_0", this);
    RX1A_0->setLogger(this->_baseLog->getChildLogger("RX1A_0", "ports"));
    addPort("RX1A_0", RX1A_0);
    RX1B_1 = new frontend::InRFInfoPort("RX1B_1", this);
    RX1B_1->setLogger(this->_baseLog->getChildLogger("RX1B_1", "ports"));
    addPort("RX1B_1", RX1B_1);
    RX2A_2 = new frontend::InRFInfoPort("RX2A_2", this);
    RX2A_2->setLogger(this->_baseLog->getChildLogger("RX2A_2", "ports"));
    addPort("RX2A_2", RX2A_2);
    RX2B_3 = new frontend::InRFInfoPort("RX2B_3", this);
    RX2B_3->setLogger(this->_baseLog->getChildLogger("RX2B_3", "ports"));
    addPort("RX2B_3", RX2B_3);
    DigitalTuner_in = new frontend::InDigitalTunerPort("DigitalTuner_in", this);
    DigitalTuner_in->setLogger(this->_baseLog->getChildLogger("DigitalTuner_in", "ports"));
    addPort("DigitalTuner_in", DigitalTuner_in);
    dataShortTX_in = new bulkio::InShortPort("dataShortTX_in");
    dataShortTX_in->setLogger(this->_baseLog->getChildLogger("dataShortTX_in", "ports"));
    addPort("dataShortTX_in", dataShortTX_in);
    TX1A_0 = new frontend::OutRFInfoPort("TX1A_0");
    TX1A_0->setLogger(this->_baseLog->getChildLogger("TX1A_0", "ports"));
    addPort("TX1A_0", TX1A_0);
    TX1B_1 = new frontend::OutRFInfoPort("TX1B_1");
    TX1B_1->setLogger(this->_baseLog->getChildLogger("TX1B_1", "ports"));
    addPort("TX1B_1", TX1B_1);
    TX2A_2 = new frontend::OutRFInfoPort("TX2A_2");
    TX2A_2->setLogger(this->_baseLog->getChildLogger("TX2A_2", "ports"));
    addPort("TX2A_2", TX2A_2);
    TX2B_3 = new frontend::OutRFInfoPort("TX2B_3");
    TX2B_3->setLogger(this->_baseLog->getChildLogger("TX2B_3", "ports"));
    addPort("TX2B_3", TX2B_3);
    dataShortRX_out = new bulkio::OutShortPort("dataShortRX_out");
    dataShortRX_out->setLogger(this->_baseLog->getChildLogger("dataShortRX_out", "ports"));
    addPort("dataShortRX_out", dataShortRX_out);

    this->addPropertyListener(connectionTable, this, &AD936X_LIBIIO_base::connectionTableChanged);

}

/*******************************************************************************************
    Framework-level functions
    These functions are generally called by the framework to perform housekeeping.
*******************************************************************************************/
void AD936X_LIBIIO_base::start() throw (CORBA::SystemException, CF::Resource::StartError)
{
    frontend::FrontendTunerDevice<frontend_tuner_status_struct_struct>::start();
    ThreadedComponent::startThread();
}

void AD936X_LIBIIO_base::stop() throw (CORBA::SystemException, CF::Resource::StopError)
{
    frontend::FrontendTunerDevice<frontend_tuner_status_struct_struct>::stop();
    if (!ThreadedComponent::stopThread()) {
        throw CF::Resource::StopError(CF::CF_NOTSET, "Processing thread did not die");
    }
}

void AD936X_LIBIIO_base::releaseObject() throw (CORBA::SystemException, CF::LifeCycle::ReleaseError)
{
    // This function clears the device running condition so main shuts down everything
    try {
        stop();
    } catch (CF::Resource::StopError& ex) {
        // TODO - this should probably be logged instead of ignored
    }

    frontend::FrontendTunerDevice<frontend_tuner_status_struct_struct>::releaseObject();
}

void AD936X_LIBIIO_base::connectionTableChanged(const std::vector<connection_descriptor_struct>* oldValue, const std::vector<connection_descriptor_struct>* newValue)
{
    dataShortRX_out->updateConnectionFilter(*newValue);
}

void AD936X_LIBIIO_base::loadProperties()
{
    addProperty(global_group_id,
                "global_group_id",
                "global_group_id",
                "readwrite",
                "",
                "external",
                "property");

    device_kind = "FRONTEND::TUNER";
    device_model = "AD936X";
    addProperty(buffer_size,
                32768,
                "buffer_size",
                "buffer_size",
                "readwrite",
                "",
                "external",
                "property");

    frontend_listener_allocation = frontend::frontend_listener_allocation_struct();
    frontend_tuner_allocation = frontend::frontend_tuner_allocation_struct();
    addProperty(fir_filter_control,
                fir_filter_control_struct(),
                "fir_filter_control",
                "fir_filter_control",
                "readwrite",
                "",
                "external",
                "property");

    addProperty(receive_chain,
                receive_chain_struct(),
                "receive_chain",
                "receive_chain",
                "readwrite",
                "",
                "external",
                "property");

    addProperty(transmit_chain,
                transmit_chain_struct(),
                "transmit_chain",
                "transmit_chain",
                "readwrite",
                "",
                "external",
                "property");

    addProperty(target_device,
                target_device_struct(),
                "target_device",
                "target_device",
                "readwrite",
                "",
                "external",
                "property");

    addProperty(connectionTable,
                "connectionTable",
                "",
                "readonly",
                "",
                "external",
                "property");

}

void AD936X_LIBIIO_base::frontendTunerStatusChanged(const std::vector<frontend_tuner_status_struct_struct>* oldValue, const std::vector<frontend_tuner_status_struct_struct>* newValue)
{
    this->tuner_allocation_ids.resize(this->frontend_tuner_status.size());
}

CF::Properties* AD936X_LIBIIO_base::getTunerStatus(const std::string& allocation_id)
{
    CF::Properties* tmpVal = new CF::Properties();
    long tuner_id = getTunerMapping(allocation_id);
    if (tuner_id < 0)
        throw FRONTEND::FrontendException(("ERROR: ID: " + std::string(allocation_id) + " IS NOT ASSOCIATED WITH ANY TUNER!").c_str());
    CORBA::Any prop;
    prop <<= *(static_cast<frontend_tuner_status_struct_struct*>(&this->frontend_tuner_status[tuner_id]));
    prop >>= tmpVal;

    CF::Properties_var tmp = new CF::Properties(*tmpVal);
    return tmp._retn();
}

void AD936X_LIBIIO_base::assignListener(const std::string& listen_alloc_id, const std::string& allocation_id)
{
    // find control allocation_id
    std::string existing_alloc_id = allocation_id;
    std::map<std::string,std::string>::iterator existing_listener;
    while ((existing_listener=listeners.find(existing_alloc_id)) != listeners.end())
        existing_alloc_id = existing_listener->second;
    listeners[listen_alloc_id] = existing_alloc_id;

    std::vector<connection_descriptor_struct> old_table = connectionTable;
    std::vector<connection_descriptor_struct> new_entries;
    for (std::vector<connection_descriptor_struct>::iterator entry=connectionTable.begin();entry!=connectionTable.end();entry++) {
        if (entry->connection_id == existing_alloc_id) {
            connection_descriptor_struct tmp;
            tmp.connection_id = listen_alloc_id;
            tmp.stream_id = entry->stream_id;
            tmp.port_name = entry->port_name;
            new_entries.push_back(tmp);
        }
    }
    for (std::vector<connection_descriptor_struct>::iterator new_entry=new_entries.begin();new_entry!=new_entries.end();new_entry++) {
        bool foundEntry = false;
        for (std::vector<connection_descriptor_struct>::iterator entry=connectionTable.begin();entry!=connectionTable.end();entry++) {
            if (entry == new_entry) {
                foundEntry = true;
                break;
            }
        }
        if (!foundEntry) {
            connectionTable.push_back(*new_entry);
        }
    }
    connectionTableChanged(&old_table, &connectionTable);
}

void AD936X_LIBIIO_base::removeListener(const std::string& listen_alloc_id)
{
    if (listeners.find(listen_alloc_id) != listeners.end()) {
        listeners.erase(listen_alloc_id);
    }
    std::vector<connection_descriptor_struct> old_table = this->connectionTable;
    std::vector<connection_descriptor_struct>::iterator entry = this->connectionTable.begin();
    while (entry != this->connectionTable.end()) {
        if (entry->connection_id == listen_alloc_id) {
            entry = this->connectionTable.erase(entry);
        } else {
            entry++;
        }
    }
    ExtendedCF::UsesConnectionSequence_var tmp;
    // Check to see if port "dataShortRX_out" has a connection for this listener
    tmp = this->dataShortRX_out->connections();
    for (unsigned int i=0; i<tmp->length(); i++) {
        const char* connection_id = tmp[i].connectionId;
        if (connection_id == listen_alloc_id) {
            this->dataShortRX_out->disconnectPort(connection_id);
        }
    }
    this->connectionTableChanged(&old_table, &this->connectionTable);
}

void AD936X_LIBIIO_base::removeAllocationIdRouting(const size_t tuner_id) {
    std::string allocation_id = getControlAllocationId(tuner_id);
    std::vector<connection_descriptor_struct> old_table = this->connectionTable;
    std::vector<connection_descriptor_struct>::iterator itr = this->connectionTable.begin();
    while (itr != this->connectionTable.end()) {
        if (itr->connection_id == allocation_id) {
            itr = this->connectionTable.erase(itr);
            continue;
        }
        itr++;
    }
    for (std::map<std::string, std::string>::iterator listener=listeners.begin();listener!=listeners.end();listener++) {
        if (listener->second == allocation_id) {
            std::vector<connection_descriptor_struct>::iterator itr = this->connectionTable.begin();
            while (itr != this->connectionTable.end()) {
                if (itr->connection_id == listener->first) {
                    itr = this->connectionTable.erase(itr);
                    continue;
                }
                itr++;
            }
        }
    }
    this->connectionTableChanged(&old_table, &this->connectionTable);
}

void AD936X_LIBIIO_base::removeStreamIdRouting(const std::string stream_id, const std::string allocation_id) {
    std::vector<connection_descriptor_struct> old_table = this->connectionTable;
    std::vector<connection_descriptor_struct>::iterator itr = this->connectionTable.begin();
    while (itr != this->connectionTable.end()) {
        if (allocation_id == "") {
            if (itr->stream_id == stream_id) {
                itr = this->connectionTable.erase(itr);
                continue;
            }
        } else {
            if ((itr->stream_id == stream_id) and (itr->connection_id == allocation_id)) {
                itr = this->connectionTable.erase(itr);
                continue;
            }
        }
        itr++;
    }
    for (std::map<std::string, std::string>::iterator listener=listeners.begin();listener!=listeners.end();listener++) {
        if (listener->second == allocation_id) {
            std::vector<connection_descriptor_struct>::iterator itr = this->connectionTable.begin();
            while (itr != this->connectionTable.end()) {
                if ((itr->connection_id == listener->first) and (itr->stream_id == stream_id)) {
                    itr = this->connectionTable.erase(itr);
                    continue;
                }
                itr++;
            }
        }
    }
    this->connectionTableChanged(&old_table, &this->connectionTable);
}

void AD936X_LIBIIO_base::matchAllocationIdToStreamId(const std::string allocation_id, const std::string stream_id, const std::string port_name) {
    if (port_name != "") {
        for (std::vector<connection_descriptor_struct>::iterator prop_itr = this->connectionTable.begin(); prop_itr!=this->connectionTable.end(); prop_itr++) {
            if ((*prop_itr).port_name != port_name)
                continue;
            if ((*prop_itr).stream_id != stream_id)
                continue;
            if ((*prop_itr).connection_id != allocation_id)
                continue;
            // all three match. This is a repeat
            return;
        }
        std::vector<connection_descriptor_struct> old_table = this->connectionTable;
        connection_descriptor_struct tmp;
        tmp.connection_id = allocation_id;
        tmp.port_name = port_name;
        tmp.stream_id = stream_id;
        this->connectionTable.push_back(tmp);
        this->connectionTableChanged(&old_table, &this->connectionTable);
        return;
    }
    std::vector<connection_descriptor_struct> old_table = this->connectionTable;
    connection_descriptor_struct tmp;
    tmp.connection_id = allocation_id;
    tmp.port_name = "dataShortRX_out";
    tmp.stream_id = stream_id;
    this->connectionTable.push_back(tmp);
    this->connectionTableChanged(&old_table, &this->connectionTable);
}

