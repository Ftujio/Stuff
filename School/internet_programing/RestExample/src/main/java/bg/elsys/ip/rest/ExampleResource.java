package bg.elsys.ip.rest;

import javax.ws.rs.GET;
import javax.ws.rs.Path;
import javax.ws.rs.PathParam;
import javax.ws.rs.Produces;
import javax.ws.rs.QueryParam;
import javax.ws.rs.core.MediaType;
import javax.ws.rs.core.Response;

@Path("/users")
public class ExampleResource {
	@GET
	@Produces(MediaType.APPLICATION_JSON)
	public Response sayhello() {
		return Response.ok(new User(1, "admin")).build();
	}
	
	//localhost:8080/RestExample/users/3?term=asd
	//localhost:8080/RestExample/users/5/products  <-- (Convention)
	@GET
	@Path("/{id}")
	public Response getUser(@PathParam("id") int id, @QueryParam("term") String term){
		return null;
	}
}
