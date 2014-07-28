//window.onload = SetupSlideshow;

function SetupSlideshow()
{
	var slide1Obj = document.getElementById("slide_1");
	var slide2Obj = document.getElementById("slide_2");
	var slide3Obj = document.getElementById("slide_3");
	var slide4Obj = document.getElementById("slide_4");
	var slide5Obj = document.getElementById("slide_5");
	var slide6Obj = document.getElementById("slide_6");
	var slide7Obj = document.getElementById("slide_7");
	var slideImages = new Array("front-page/Arduino-voltmeter-lcd.jpg",
								 "front-page/open-source-plc-small.jpg",
								 "front-page/arduino-ethernet-web-server.jpg",
								 "front-page/vhdl-cpld.jpg",
								 "front-page/rc-watermelon.jpg",
								 "front-page/blowing-up-resistor.jpg",
								 "front-page/CPLD-board.jpg");

	preloadImages(['front-page/Arduino-voltmeter-lcd.jpg',
				   'front-page/open-source-plc-small.jpg',
				   'front-page/arduino-ethernet-web-server.jpg',
				   'front-page/vhdl-cpld.jpg',
				   'front-page/rc-watermelon.jpg',
				   'front-page/blowing-up-resistor.jpg',
				   'front-page/CPLD-board.jpg']);

	if (slide1Obj) {
		slide1Obj.onmouseover = function() {
			document.getElementById("slide_pic").src = slideImages[0];
			document.getElementById("slide_img_link").href = "/projects/arduino-projects/arduino-4-channel-LCD-voltmeter";
			document.getElementById("slide_1").style.borderLeftStyle = "hidden";
			CloseLeftBox(1);
		}
	}
	if (slide2Obj) {
		slide2Obj.onmouseover = function() {
			document.getElementById("slide_pic").src = slideImages[1];
			document.getElementById("slide_img_link").href = "/projects/small-open-source-PLC";
			document.getElementById("slide_2").style.borderLeftStyle = "hidden";
			CloseLeftBox(2);
		}
	}
	if (slide3Obj) {
		slide3Obj.onmouseover = function() {
			document.getElementById("slide_pic").src = slideImages[2];
			document.getElementById("slide_img_link").href = "/tutorials/arduino/ethernet-shield-web-server-tutorial";
			document.getElementById("slide_3").style.borderLeftStyle = "hidden";
			CloseLeftBox(3);
		}
	}
	if (slide4Obj) {
		slide4Obj.onmouseover = function() {
			document.getElementById("slide_pic").src = slideImages[3];
			document.getElementById("slide_img_link").href = "/software/VHDL-CPLD-course";
			document.getElementById("slide_4").style.borderLeftStyle = "hidden";
			CloseLeftBox(4);
		}
	}
	if (slide5Obj) {
		slide5Obj.onmouseover = function() {
			document.getElementById("slide_pic").src = slideImages[4];
			document.getElementById("slide_img_link").href = "/articles/radio-controlled-watermelon";
			document.getElementById("slide_5").style.borderLeftStyle = "hidden";
			CloseLeftBox(5);
		}
	}
	if (slide6Obj) {
		slide6Obj.onmouseover = function() {
			document.getElementById("slide_pic").src = slideImages[5];
			document.getElementById("slide_img_link").href = "/articles/blowing-up-a-resistor";
			document.getElementById("slide_6").style.borderLeftStyle = "hidden";
			CloseLeftBox(6);
		}
	}
	if (slide7Obj) {
		slide7Obj.onmouseover = function() {
			document.getElementById("slide_pic").src = slideImages[6];
			document.getElementById("slide_img_link").href = "/projects/xilinx-CPLD-board";
			document.getElementById("slide_7").style.borderLeftStyle = "hidden";
			CloseLeftBox(7);
		}
	}
}

function CloseLeftBox (currentBox)
{
	for (var i = 1; i < 8; i++) {
		if (i != currentBox) {
			document.getElementById("slide_" + i).style.borderLeftStyle = "solid";
		}
	}
}

function preloadImages(arr)
{
	var newimages = [];
	var arr = (typeof arr!="object") ? [arr] : arr; // force arr parameter to always be an array
    for (var i = 0; i < arr.length; i++) {
		newimages[i] = new Image();
		newimages[i].src = arr[i];
	}
}
