package bg.elsys.ip.rest;

import javax.ws.rs.GET;
import javax.ws.rs.Path;
import javax.ws.rs.Produces;
import javax.ws.rs.core.MediaType;
import javax.ws.rs.core.Response;

@Path("/users")
public class UserResource {
	@GET
	@Produces(MediaType.APPLICATION_JSON)
	public Response getUsers() {
		return Response.ok(new User(1, "asdf")).build();
	}
}
