import bb.cascades 1.0

Container {
    layout: DockLayout {
            }
    ImageView {
        image: "assets://images/background"
        preferredWidth: 768
        preferredHeight: 1280
    }
    Container {
        layout: StackLayout {}
        layoutProperties: DockLayoutProperties {
            horizontalAlignment: HorizontalAlignment.Center;
            verticalAlignment: VerticalAlignment.Center;
        }
        topMargin: 10
        bottomMargin: 10
        preferredWidth: 768
        preferredHeight: 1280
        Label {
            objectName: "userName"
            topMargin: 10; bottomMargin: 10;
            layoutProperties: StackLayoutProperties {verticalAlignment: VerticalAlignment.Top; horizontalAlignment: HorizontalAlignment.Center;}
        }
        Button {
		    objectName: "logoutButton"
		    text: "Logout"
        }
    }
}