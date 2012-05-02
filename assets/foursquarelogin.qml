import bb.cascades 1.0

Container {
    layout: DockLayout {}
    ImageView {
        image: "assets://images/background"
        preferredWidth: 768
        preferredHeight: 1280
    }
    Container {
        layout: StackLayout {}
        layoutProperties: DockLayoutProperties {
            horizontalAlignment: HorizontalAlignment.Center;
            verticalAlignment: VerticalAlignment.Center
        }
        preferredWidth: 768
        preferredHeight: 600
	    Button {
	        id: loginButton
	        objectName: "login"
	        text: "Login"
	        layoutProperties: StackLayoutProperties {
	            verticalAlignment: VerticalAlignment.Center
	            horizontalAlignment: HorizontalAlignment.Center;
	        }
	    }
    }
}