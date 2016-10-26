function getData() {
	$.ajax({
		url: "http:localhost:8181/rst/api/users",
		type: "GET",
		dataType: "json",
		success: function(data){ // When the GET request is successful
			console.log(data);
			$.each(data, function(index){
				var tr = $('<tr>');
				tr.append('<td>' + data[index].id + '</td>');
				tr.append('<td>' + data[index].name + '</td>');
				tr.append('</tr>');
				$('#usersTable').append(tr);
			});
		}
	});
}

$(document).ready(fucntion() {
	alert('page loaded');
	$('#button').click(fucntion() {
		alert('button clicked');
		getData();
	});
});