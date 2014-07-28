window.onload = InitAll;

function InitAll()
{
	OpenLinkInNewWindow();
	RevolvingFundRaiser();
	
	var loc = window.location.pathname;
	var dir = loc.substring(0, loc.lastIndexOf('/'));

	if (dir == "") {	// only run slideshow if on home page
		SetupSlideshow();
	}
}

/* links with the class name "targetblank" will be opened in  a new window */
function OpenLinkInNewWindow()
{
	// Code if document.getElementByClassName() doesn't exist
	if (document.getElementsByClassName == undefined) {
		document.getElementsByClassName = function(className) {
			var hasClassName = new RegExp("(?:^|\\s)" + className + "(?:$|\\s)");
			var allElements = document.getElementsByTagName("*");
			var results = [];

			var element;
			for (var i = 0; (element = allElements[i]) != null; i++) {
				var elementClass = element.className;
				if (elementClass && elementClass.indexOf(className) != -1 && hasClassName.test(elementClass)) {
					results.push(element);
				}
			}
			return results;
		}
	}

	var anchorList = document.getElementsByClassName('targetblank');
	for (var i in anchorList) {
		anchorList[i].target = '_blank';
	}
}
