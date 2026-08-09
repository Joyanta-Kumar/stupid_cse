## Table of Contents

| S.No | Algorithm |
|:----:|:----|
| 1 | Study physical equipments of network |
| 2 | Study OSI and TCP model |
| 3 | Transmission media |
| 4 | Network topologies  |
| 5 | LAN using STAR topology |
| 6 | LAN using BUS topology |
| 7 | LAN using HYBRID topology |
| 8 | Modem |
| 9 | Hub |
| 10 | Peer to peer communication |
| 11 | Resource sharing |
| 12 | Build Local Area Network |

# Study physical equipments of network.

## Objective
To study about different physical equipment used for networking.

## Apparatus
1. Repeater
2. Hub
3. Switch
4. Router

## Theory
Computer networks rely on several hardware devices to transmit, regenerate, filter, and direct data between connected systems.

- **Repeater**: A physical layer device that receives a weak signal and retransmits its amplified version extending transmission distance.
- **Hub**: A physical layer device connecting multiple computer. It broadcasts incoming data to all ports with no intelligence.
- **Switch**: A data link layer device that uses MAC address to forward data only to the intended port, reducing collisions.
- **Router**: A network layer device that connects different networks and forwards packets based on IP address using a routing table.

## Procedure:

1. Identify and physically examine each device.
2. Note the number and type of ports on each device.
3. Observe indicator lights on each device.
4. Connect a device to two computers and observe data forwarding behavior.
5. Compare broadcast behavior of a hub versus a switch using simple ping tests.
6. Record observations for each device's function and OSI layer.

<div class="page-brake"></div>

## Observation

| Device | OSI Layer | Function |
| ------ | --------- | -------- |
| Repeater | Physical | Amplifies signal |
| Hub | Physical | Broadcasts signal |
| Switch | Data Link | Forwards frame to a specific machine | 
| Router | Network | Routes packets using IP address |

<div class="page-brake"></div>

# Study OSI and TCP model

## Objective
To study the OSI reference model and TCP/IP reference model.

## Theory
The Open System Interconnection model is a 7-layer conceptual framework by ISO standardizing communication functions. The TCP model is a 4-layer, implementation-based model forming the basis of the internet.

| OSI Layer | Function |
| --------- | -------- |
| Application | Provides services to end-user |
| Presentation | Data translation, encryption, compression |
| Session | Establish and manage sessions |
| Transport | Reliable end-to-end delivery |
| Network | Logical addressing and routing |
| Data Link | Physical address and error detection |
| Physical | Transmission of raw bits |

<br>

| TCP Layer | Corresponding OSI Layer |
| --------- | ----------------------- |
| Application | Application, Presentation, Session |
| Transport | Transport |
| Internet | Network |
| Network Access | Data Link, Physical |

## Procedure
1. Draw the 7-layer OSI model stack.
2. Draw the 4-layer TCP model stack alongside it.
3. Map each TCP layer to its corresponding OSI layer.
4. List protocols associated with each layer.
5. Compare the two models for similarities and differences.

<div class="page-brake"></div>

## Figure

<table border=1>
<tr>
    <th>OSI Model</th>
    <th>TCP Model</th>
</tr>
<tr>
    <td>Application</td>
    <td rowspan=3>Application</td>
</tr>
<tr>
    <td>Presentation</td>
</tr>
<tr>
    <td>Session</td>
</tr>
<tr>
    <td>Transport</td>
    <td>Transport</td>
</tr>
<tr>
    <td>Network</td>
    <td>Internet</td>
</tr>
<tr>
    <td>Data Link</td>
    <td rowspan=2>Network Access</td>
</tr>
<tr>
    <td>Physical</td>
</tr>
</table>


<div class="page-brake"></div>

# Transmission media

## Objective
To study different types of transmission media

## Apparatus
1. Twisted pair cable
2. Coaxial cable
3. Fiber optic cable

## Theory
Transmission media are classified into guided and unguided media.

### Guided
- Twisted pair cable: Two twisted insulated copper wires reducing interference.
- Coaxial cable: Central conductor with shielding.
- Fiber optic cable: Transmits light pulses.

### Unguided 
- Radio wave: Long distance wireless (radio, wifi).
- Microwave: Point to Point and in line of sight (satellite links).
- Infrared: Short range (remote control).

| Medium | Bandwith | Cost | Interference immunity |
| ------ | -------- | ---- | --------------------- |
| Twisted Pair | Low-Medium | Low | Low |
| Coaxial | Medium | Medium | Medium |
| Fiber Optic | Very High | High | Very High |

## Procedure
1. Physically examine samples of twisted pair, coaxial, and fiber optic cables.
2. Note the construction (conductor, insulation, shielding, jacket) of each.
3. Compare connector types (RJ-45, BNC, ST/SC).
4. Discuss typical use cases for each medium.
5. Tabulate bandwidth, cost, and interference resistance.

<div class="page-brake"></div>

#  Network topologies 

## Objective
Study network topologies with advantages & disadvantages.

## Apparatus
1. Reference chart
2. Packet tracer

## Theory
Network topology is the physical/logical arrangement of nodes and links.

| Topology | Description | Advantages | Disadvantages |
| --- | --- | --- | --- |
| Bus | All devices on one backbone cable | Easy to install, less cable | Entire network fails if backbone breaks |
| Star | All devices connect to central hub/switch | Easy management; isolated failures | Central device failure disables network |
| Ring | Devices connected in a closed loop | Orderly transmission | One break can disrupt whole network |
| Mesh | Every device connected to every other | Highly reliable | Costly, complex | 
| Tree, Star | networks joined via bus backbone | Scalable | Backbone dependency |
| Hybrid | Combination of two or more topologies | Flexible, scalable | Complex, costly |

## Procedure
1. Draw each topology (bus, star, ring, mesh, tree, hybrid).
2. Simulate each layout in Packet Tracer (where possible).
3. Identify central points of failure for each.
4. List advantages/disadvantages based on observation.


<div class="page-brake"></div>

#  LAN using STAR topology.

## Objective
To study LAN using STAR topology.

## Apparatus
1. RJ-45 connector
2. Crimping tool
3. Twisted pair cable
4. Desktop computer
5. Command Prompt
6. Cisco Packet Tracer

## Theory
In STAR topology, every node connects individually to a central switch/hub. All communication passes through the central device, making it easy to manage and troubleshoot.

## Procedure
1. Open Packet Tracer; place one Switch and required PCs.
2. Connect each PC to the switch using straight-through cable.
3. Assign static IP addresses/subnet masks to each PC (Desktop > IP Configuration).
4. Confirm green link lights on all ports.
5. Open Command Prompt and ping another PC's IP address.
6. Record successful reply confirming connectivity.

<div class="page-brake"></div>

#  LAN using BUS topology.

## Objective
To study LAN using BUS topology.

## Apparatus
1. RJ-45 connector
2. Crimping tool
3. Twisted pair cable
4. Desktop computer
5. Command Prompt
6. Cisco Packet Tracer

## Theory
In BUS topology, all devices share a single backbone cable. Data travels along the bus; only the intended recipient processes it. Terminators prevent signal reflection at both ends.


## Procedure
1. Open Packet Tracer; place one Switch and required PCs.
2. Connect all PCs to a shared backbone cable (T-connector/drop cable representation).
3. Assign static IP addresses/subnet masks to each PC (Desktop > IP Configuration).
4. Confirm green link lights on all ports.
5. Open Command Prompt and ping another PC's IP address.
6. Record successful reply confirming connectivity.

<div class="page-brake"></div>

#  LAN using HYBRID topology.

## Objective
To study LAN using HYBRID topology.

## Apparatus
1. RJ-45 connector
2. Crimping tool
3. Twisted pair cable
4. Desktop computer
5. Command Prompt
6. Cisco Packet Tracer

## Theory
HYBRID topology combines two or more basic topologies (e.g., multiple star networks joined by a backbone). It combines advantages of constituent topologies for flexibility and fault tolerance, at higher design complexity.

## Procedure
1. Design two or more star networks, each with its own switch and PCs.
2. Connect the switches together via a backbone link.
3. Assign static IPs to all PCs (segmented subnets if needed).
4. Verify all links are active.
5. Ping from a PC in one segment to a PC in another segment.
6. Record whether connectivity succeeds.

<div class="page-brake"></div>

# MODEM

## Objective
Study configure MODEM of computer.

## Apparatus
1. Modem (dial-up/DSL)
2. Telephone/LAN line
3. Desktop computer

## Theory
A MODEM (Modulator-Demodulator) converts digital signals to analog for transmission over telephone/cable lines (modulation) and converts incoming analog signals back to digital (demodulation), enabling Internet access via an ISP.

## Procedure
1. Connect the modem to the computer (USB/Ethernet) and the line to the modem's WAN port.
2. Power on the modem; wait for stable indicator lights.
3. Open Control Panel > Network and Sharing Center > Set up a new connection.
4. Select Broadband/PPPoE; enter ISP-provided username and password.
5. Save configuration and click Connect.
6. Verify Internet connectivity via browser or ping.

<div class="page-brake"></div>


# HUB

## Objective
Study configure HUB of computer.

## Apparatus
1. Hub
2. Twisted pair cable
3. Desktop computer

## Theory
Configuring a switch involves connecting devices and, for managed switches, assigning IP addresses, VLANs, and port settings via CLI/web interface. Unmanaged hubs/switches are plug-and-play.

## Procedure
1. Power on the hub/switch.
2. Connect each computer to a port using Ethernet cables.
3. For managed switch: connect via console port, open terminal (PuTTY).
4. Assign management IP: interface vlan 1 → ip address <ip> <subnet mask>.
5. Configure ports (enable/disable, speed, duplex) as needed.
6. Save configuration; verify by pinging the switch's management IP.

<div class="page-brake"></div>

# Peer to peer communication

## Objective
Connect two PCs using peer to peer communication

## Apparatus
1. Two Desktop computers
2. Crossover/Straight-through cable
3. RJ-45 connector

## Theory
Peer-to-peer (P2P) networking connects two computers directly without an intermediate device. A crossover cable is traditionally required (modern NICs with Auto-MDIX allow straight-through cables too).

## Procedure
1. Prepare a crossover cable using an RJ-45 crimping tool.
2. Connect one end to PC1's Ethernet port, other end to PC2.
3. Assign static IP to PC1 (e.g., 192.168.1.1/24).
4. Assign static IP to PC2 in same subnet (e.g., 192.168.1.2/24).
5. Open Command Prompt and ping the other PC's IP.
6. Observe reply packets confirming communication.

<div class="page-brake"></div>

# Resource sharing
## Objective
To study and perform resource sharing over a network.

## Apparatus
1. Two Desktop computers
2. Shared folder
3. Printer

## Theory
Resource sharing allows multiple networked users to access shared hardware (printers) and data (folders/files) from a central or peer location, reducing cost and improving collaboration.

## Procedure
1. Right-click folder > Properties > Sharing > Advanced Sharing.
2. Check "Share this folder"; set share name.
3. Set Permissions (Read/Write) for users.
4. Apply/OK to enable sharing.
5. Access from another PC via `\\<IP address>\<share name>`.

<div class="page-brake"></div>

# Resource sharing

## Objective
To study and perform resource sharing over a network.

## Apparatus
1. Two Desktop computers
2. Shared folder
3. Printer

## Theory
Resource sharing allows multiple networked users to access shared hardware (printers) and data (folders/files) from a central or peer location, reducing cost and improving collaboration.

## Procedure
1. Right-click folder > Properties > Sharing > Advanced Sharing.
2. Check "Share this folder"; set share name.
3. Set Permissions (Read/Write) for users.
4. Apply/OK to enable sharing.
5. Access from another PC via `\\<IP address>\<share name>`.

# Build Local Area Network

## Objective
To build computers network in a Local Area Network (LAN).

## Apparatus
1. Switch
2. Twisted pair cables
3. RJ-45 connectors
4. Desktop computers

## Theory
A LAN connects computers within a limited area (lab/office/building) for high-speed data/resource sharing. Building one involves cabling, IP addressing, and connectivity verification.

## Procedure 
1. Prepare RJ-45 terminated straight-through cables (T568B standard) using a crimping tool.
2. Connect each computer's Ethernet port to the switch.
3. Power on switch/computers; confirm active link lights.
4. Assign unique static IPs in the same subnet to each PC (e.g., 192.168.10.1–x /24).
5. Verify connectivity between every pair of PCs using ping.
6. Enable file/printer sharing as needed.
