"use strict";
jQuery(document).ready(function ($) {
	
	//for Preloader
    $(window).on('load',function () {
        $("#loading").fadeOut(500);
	});
	
	
    /*---------------------------------------------*
		* Mobile menu
	---------------------------------------------*/
    $('#navbar-menu').find('a').click(function () {
        if (location.pathname.replace(/^\//, '') == this.pathname.replace(/^\//, '') && location.hostname == this.hostname) {
            var target = $(this.hash);
            target = target.length ? target : $('[name=' + this.hash.slice(1) + ']');
            if (target.length) {
				if ($('.navbar-toggle').css('display') != 'none') {
					// means in mobile mode, navbar is collapsed
					$(this).parents('.container').find(".navbar-toggle").trigger("click");
					$('html,body').animate({
						scrollTop: (target.offset().top - 300)
					}, 1000);
				}
				else{
					//normal mode full width
					$('html,body').animate({
						scrollTop: (target.offset().top)
					}, 1000);
				}	
				return false;
			}
		}
	});
	
	// 2- Setups up waypoint to indicate a new section
	/*var yourNameWaypoint1 = new Waypoint({
		
		// 3- Target an ID for waypoints to watch, corresponds to a page section
		element: document.getElementById('home'),
		handler: function(direction) {
		history.pushState(null, "Home", "");
		},
		offset:-10
	});*/
	
	
	
	/*---------------------------------------------*
		* WOW
	---------------------------------------------*/
	
/*	var wow = new WOW({
		mobile: false // trigger animations on mobile devices (default is true)
	});
	wow.init();
*/
	// magnificPopup
	
	// slick slider active Home Page Tow
	$(".hello_slid").slick({
		dots: true,
		infinite: false,
		slidesToShow: 1,
		slidesToScroll: 1,
		arrows: true,
		prevArrow: "<i class='icon icon-chevron-left nextprevleft'></i>",
		nextArrow: "<i class='icon icon-chevron-right nextprevright'></i>",
		autoplay: true,
		autoplaySpeed: 2000
	});
	
	
	
	$(".business_items").slick({
		dots: true,
		infinite: false,
		slidesToShow: 1,
		slidesToScroll: 1,
		arrows: true,
		prevArrow: "<i class='icon icon-chevron-left nextprevleft'></i>",
		nextArrow: "<i class='icon icon-chevron-right nextprevright'></i>",
		autoplay: true,
		autoplaySpeed: 2000
	});
	
	$("#home_scroll").slick({
		dots: true,
		infinite: true,
		arrows: true,
		prevArrow: "<i class='icon icon-chevron-left nextprevleft'></i>",
		nextArrow: "<i class='icon icon-chevron-right nextprevright'></i>",
		autoplay: true,
		autoplaySpeed: 2000,
		speed: 1000,
		fade:true,
		cssEase: 'linear'
	});
	
	
	//---------------------------------------------
	// Scroll Up 
	//---------------------------------------------
	
	$('.scrollup').click(function () {
		$("html, body").animate({scrollTop: 0}, 1000);
		return false;
	});
	
	//End
});



