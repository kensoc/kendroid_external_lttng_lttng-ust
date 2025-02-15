/*
 * Copyright (C) 2014 - Christian Babeux <christian.babeux@efficios.com>
 *
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License, version 2.1 only,
 * as published by the Free Software Foundation.
 *
 * This library is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License
 * for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

package org.lttng.ust.jul;

import java.io.IOException;

@Deprecated
public class LTTngAgent {

	/*
	 * !!! WARNING !!!
	 * Please use the LTTngAgent found in the org.lttng.ust.agent package.
	 * This class is DEPRECATED.
	 */

	private static LTTngAgent curAgent = null;
	private static org.lttng.ust.agent.LTTngAgent realAgent = null;


	private LTTngAgent() throws IOException {
		realAgent = org.lttng.ust.agent.LTTngAgent.getLTTngAgent();
	}

	public static synchronized LTTngAgent getLTTngAgent() throws IOException {
		if (curAgent == null) {
			curAgent = new LTTngAgent();
		}

		return curAgent;
	}

	public void dispose() throws IOException {
		realAgent.dispose();
	}
}
