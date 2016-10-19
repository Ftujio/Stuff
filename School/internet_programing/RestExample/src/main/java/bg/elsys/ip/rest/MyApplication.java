package bg.elsys.ip.rest;

import org.glassfish.jersey.jackson.JacksonFeature;
import org.glassfish.jersey.server.ResourceConfig;

public class MyApplication extends ResourceConfig {
	public MyApplication() {
		packages("org.elsys.ip.rest*");
		register(JacksonFeature.class);
	}
}
