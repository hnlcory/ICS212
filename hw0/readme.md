<!DOCTYPE html>
<html>
<head>
	<link href='https://fonts.googleapis.com/css?family=Inconsolata' rel='stylesheet' type='text/css'>
	<link rel="stylesheet" href="https://www.w3schools.com/w3css/4/w3.css">
	<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">
	<link rel="stylesheet" href="../../css/style.css" type="text/css">

	<script src="https://cdn.jsdelivr.net/npm/marked/marked.min.js"></script>
	<script src="../../js/formats.js"></script>
	<script>
		makeHWTitle("0");
		makeHWHeader('../../js/templates/header.md');
		makePage("./hw0.md");
		makeHWFooter('../../js/templates/footer.md');
	</script>

	<meta charset="UTF-8">
	<meta name="viewport" content="width=device-width, initial-scale=1">
</head>

<body>
	<!-- Icon Bar (Sidebar - hidden on small screens) -->
	<nav class="w3-sidebar w3-bar-block w3-small w3-hide-small w3-center" id="largeNavbar">
	</nav>

	<!-- Navbar on small screens (Hidden on medium and large screens) -->
	<div class="w3-top w3-hide-large w3-hide-medium" id="smallNavbar">
	  <div class="w3-bar w3-black w3-center w3-small">
	  </div>
	</div>

	<!-- Page Content -->
	<div class="w3-padding-large" id="main">
		<!-- title goes here -->
		<h1 class='title'></h1>
		<!-- header -->
		<div id='header'></div>
		<!-- main content from markdown -->
		<div id='content'></div>
		<!-- footer -->
		<div id='footer'></div>
	</div>

</body>
</html>
