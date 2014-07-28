//window.onload = RevolvingFundRaiser;

thisFundRaiser = 0;

function RevolvingFundRaiser()
{
	var fundItems = new Array(	"Thanks J.C. for your $20 Donation!",
								"Thanks A.L. for your $10 Donation!",
								"Thanks R.V.S for your $10 Donation!",
								"Thanks R.S. for your $20 Donation!",
								"Thanks T.S. for your $5 Donation!",
								"Thanks J.P. for your $10 Donation!",
								"Thanks G.S. for your $5 Donation!",
								"Thanks W.S. for your $12 Donation!");

	document.getElementById("fundraiser_par").innerHTML = fundItems[thisFundRaiser];
	setTimeout(RevolvingFundRaiser, 3 * 1000);
	thisFundRaiser++;
	if (thisFundRaiser == fundItems.length) {
		thisFundRaiser = 0;
	}
}
