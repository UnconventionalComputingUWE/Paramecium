# Paramecium
Contained in this github are files to create and test artificial cilia.

%%%% Board manufacture %%%%
The eagle files are included in the github so that users may produce articifial cilia. There is a free version of EagleCAD for all users which allows for the modification and design of 2 layered boards, so anyone can edit the files. Some board manufacturers accept EagleCad files however some companies only accept Gerber files; there is a simple method of converting EagleCAD designs to Gerbers in the software.

%%%% Assembling the boards %%%%
The parts can be assembled on the boards by the user or by the board manufacturer should they have such capabilities. Some components are through-hole and some are surface-mount; both can be soldered by hand by anyone with reasonable soldering proficiency.

%%%% Uploading files to the board %%%%
You must upload the hex files (both the supplied one, and user created ones) using an ISP.
We used AVRDUDE to upload hex files via a USBtinyISP AVR Programmer Kit (USB SpokePOV Dongle) - v2.0. Other ISP devices may work.

Anyone is free to use and modify these designs and code for their use. Please provide appropriate credit, such as citations. Commercial use is permitted.
